#include "joystickapplication.h"
#include "xf/xfevent.h"

using namespace app;

JoystickApplication::JoystickApplication()
    : _currentState(STATE_UNKOWN)
{
    _currentPosition.position = IJoystick::Invalid;
}

JoystickApplication::~JoystickApplication(){}

void JoystickApplication::initialize(){}

void JoystickApplication::start(){
    startBehavior();
}

void JoystickApplication::onPositionChange(IJoystick::Position position){
    _currentPosition = position;

    GEN(XFEvent(EV_EV_CHANGE_id));
}

EventStatus JoystickApplication::processEvent(){

    eMainState newState = _currentState;

    switch (_currentState){

    case STATE_UNKOWN:
    case STATE_INITIAL:
        if (getCurrentEvent()->getEventType() == IXFEvent::Initial){
            newState = STATE_ROOT;
        }
        break;

    case STATE_ROOT:
        if (getCurrentEvent()->getEventType() == IXFEvent::Event &&
            getCurrentEvent()->getId() == EV_EV_CHANGE_id)
        {
            newState = STATE_ROOT;

            uint8_t value = static_cast<uint8_t>(_currentPosition.position);

            desenet::SharedByteBuffer ev(1);
            ev[0] = value;

            evPublishRequest(EVID_JOYSTICK, ev);
        }
        break;
    }

    _currentState = newState;
    return EventStatus::Consumed;
}
