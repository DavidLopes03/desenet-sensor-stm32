#include "desenet/sensor/net.h"
#include "abstractapplication.h"

using desenet::sensor::AbstractApplication;

/*********************************************************************************************************
* TODO: Implement the protected methods of the AbstractApplication class here. From these you have to    *
* call the different methods on your DESENET Controller Entity implementation...                         *
*********************************************************************************************************/

// Default implementations.

/**
 * @brief AbstractApplication::svSyncRequest : Register an application
 */
void AbstractApplication::svSyncRequest(){
    // TODO: Register application using the network entity

    // Register this application with the NetworkEntity to receive sync signals
    desenet::sensor::Net::instance().entity().registerApplication(this);
}


/**
 * @brief AbstractApplication::svPublishRequest : Requests permission to publish Sampled Values for a specific group
 * @param group
 * @return
 */
bool AbstractApplication::svPublishRequest(SvGroup group){
    // TODO: Register application for the provided group using the network entity
    return desenet::sensor::Net::instance().entity().registerPublisher(this, group);
}

/**
 * @brief AbstractApplication::evPublishRequest : Requests to publish an asynchronous event
 * @param id
 * @param evData
 */
void AbstractApplication::evPublishRequest(EvId id, const SharedByteBuffer & evData){
    // TODO: Publish event data

    // Queue the event in the NetworkEntity for transmission in the next slot
    desenet::sensor::Net::instance().entity().queueEvent(id, evData);
}

/**
 * Default callback method for syncs
 */
void AbstractApplication::svSyncIndication(desenet::NetworkTime){}

/**
 * Default callback method for SV publishes
 */
SharedByteBuffer::sizeType AbstractApplication::svPublishIndication(SvGroup, SharedByteBuffer &){
	return 0;
}
