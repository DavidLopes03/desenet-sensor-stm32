#include <assert.h>
#include <array>
#include <list>
#include <map>
#include <vector>
#include <utility>
#include "platform-config.h"
#include "board/ledcontroller.h"
#include "desenet/frame.h"
#include "desenet/beacon.h"
#include "desenet/timeslotmanager.h"
#include "abstractapplication.h"
#include "networkentity.h"
#include <cstdio>
#include <iostream>
using namespace std;
using std::array;
using std::list;
using std::map;
using std::make_pair;
using std::bind;
using std::pair;
using std::vector;

using desenet::sensor::NetworkEntity;

NetworkEntity * NetworkEntity::_pInstance(nullptr);		// Instantiation of static attribute

NetworkEntity::NetworkEntity()
 : _pTimeSlotManager(nullptr),
   _pTransceiver(nullptr)
{
	assert(!_pInstance);		// Only one instance allowed
	_pInstance = this;
}

NetworkEntity::~NetworkEntity(){}

void NetworkEntity::initialize(){}

/**
 * @brief NetworkEntity::initializeRelations : init relations with lower layers
 * @param timeSlotManager
 * @param transceiver
 */
void NetworkEntity::initializeRelations(ITimeSlotManager & timeSlotManager, NetworkInterfaceDriver & transceiver){

    _pTimeSlotManager = &timeSlotManager;
    _pTransceiver = &transceiver;
    // TODO: Add additional initialization code here

    //Register entity as an observer
    timeSlotManager.initializeRelations(*this);

     // Set the receive callback between transceiver and network. Bind this pointer to member function
    transceiver.setReceptionHandler(std::bind(&NetworkEntity::onReceive, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));
}

/**
 * This method does not automatically create an instance if there is none created so far.
 * It is up the the developer to create an instance of this class prior to access the instance() method.
 */
//static
NetworkEntity & NetworkEntity::instance(){
	assert(_pInstance);
    return *_pInstance;
}

/**
 * @brief NetworkEntity::slotNumber : Returns the slot number assigned to this node
 * @return slot number
 */
SlotNumber NetworkEntity::slotNumber() const{
    return timeSlotManager().slotNumber();
}

/**
 * @brief NetworkEntity::registerApplication : Registers an application to receive sync signals
 * @param app
 */
void NetworkEntity::registerApplication(AbstractApplication * app){
    appSyncList.push_back(app);
}


/**
 * @brief NetworkEntity::registerPublisher : Register an application for the provided group
 * @param app
 * @param group
 * @return Always true
 */
bool NetworkEntity::registerPublisher(AbstractApplication * app, SvGroup group){
    appPublishers[group] = app;
    return true;
}



/**
 * @brief NetworkEntity::queueEvent : Add an Event id and data in queue
 * @param id
 * @param data
 */
void NetworkEntity::queueEvent(EvId id, const SharedByteBuffer & data){
    eventList.emplace_back(id, data);
}

/**
 * @brief NetworkEntity::prepareMultiPDU : prepare the multi PDU frame calling multipdu methods
 */
void NetworkEntity::prepareMultiPDU()
{

    //resets the multi PDU frame
    _multiPDU.reset(slotNumber());
    //cout << "mPDU reset" << endl; //debug

    // Collect Sampled Values from all registered publishers
    for (SvGroup group = 0; group < appPublishers.size(); ++group){

        if (auto * app = appPublishers[group]){
            //cout << "[DEBUG] Calling svPublishIndication on group " << int(group) << endl; //debug

            SharedByteBuffer buffer(6);
            //cout << "[DEBUG] 1 " << endl; //debug

            auto size = app->svPublishIndication(group, buffer);
            //cout << "[DEBUG] 2 " << endl; //debug
            if (size > 0){
                //cout << "[DEBUG] 3 " << endl; //debug
                _multiPDU.addSvEPDU(group, buffer.data(), size);
                //cout << "[DEBUG] 4 " << endl; //debug
            }
            else{
                //cout << "size = 0" << endl; //debug
            }
        }
    }
    //cout << "mPDU sv done" << endl; //debug

    //Add each event to multi PDU frame
    for (const auto & event : eventList){
        _multiPDU.addEvEPDU(event.id, event.data.data(), event.data.size());
    }
    //cout << "mPDU ev done" << endl; //debug

    //finaliza multi PDU frame
    _multiPDU.finalize();
    //cout << "mPDU finalize" << endl; //debug

    //clears envent list
    eventList.clear();
    //cout << "mPDU ev clear" << endl; //debug
}


/**
 * Called by the NetworkInterfaceDriver (layer below) after reception of a new frame
 */
/**
 * @brief NetworkEntity::onReceive
 * @param driver
 * @param receptionTime
 * @param buffer
 * @param length
 */
void NetworkEntity::onReceive(NetworkInterfaceDriver & driver, const uint32_t receptionTime, const uint8_t * const buffer, size_t length)
{
    (void)(driver);
    (void)(receptionTime);
	Frame frame = Frame::useBuffer(buffer, length);
    // TODO: Add your code here

    // Detects beacon
    if(frame.type() == FrameType::Beacon){


        //cout << "beacon detected\n" << endl; //debug
        Beacon beacon(frame);

        // Extract slot duration from beacon
        desenet::SlotDuration duration = beacon.slotDuration();
        //ledController().flashLed(0); //flash led when beacon

        // Synchronize the TimeSlotManager with the network cycle
        timeSlotManager().onBeaconReceived(duration);
        // Notify all registered applications to sample their values (Sync)
        for (auto * app : appSyncList) {
            if (app) {
                app->svSyncIndication(0);//change with beacon value
            }
        }

        //cout << "preparing the multipdu\n" << endl; //debug

        //calls multi PDU preparation
        prepareMultiPDU();
        //cout << "multipdu prepared\n" << endl; //debug


    }
}

/**
 * @brief NetworkEntity::onTimeSlotSignal
 * @param timeSlotManager
 * @param signal
 */
void NetworkEntity::onTimeSlotSignal(const ITimeSlotManager & timeSlotManager, const ITimeSlotManager::SIG & signal){

    // check if signal indicats our assigned time slot
    if(signal == timeSlotManager.OWN_SLOT_START){

        // Transmit multi PDU frame
        (*_pTransceiver) << _multiPDU;
    }
}

board::LedController & NetworkEntity::ledController() const
{
    return board::LedController::instance();
}
