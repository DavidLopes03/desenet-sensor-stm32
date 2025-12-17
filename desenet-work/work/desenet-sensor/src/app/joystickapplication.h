#ifndef JOYSTICKAPPLICATION_H
#define JOYSTICKAPPLICATION_H

#include "platform-config.h"
#include "xf/xfreactive.h"
#include "desenet/sensor/abstractapplication.h"
#include "interfaces/ijoystickobserver.h"

namespace app {

class JoystickApplication : public XFReactive,
                            public desenet::sensor::AbstractApplication,
                            public IJoystickObserver
{
public:
    JoystickApplication();
    virtual ~JoystickApplication();

    void initialize();
    void start();
    virtual void onPositionChange(IJoystick::Position position);

private:
    IJoystick::Position _currentPosition;
protected:
    virtual EventStatus processEvent();
protected:
    /**
     * Event identifier(s) for this state machine
     */
    typedef enum
    {
        EV_EV_CHANGE_id = 1	///< Event values change event.
    } eEventId;

    /**
     * Enumeration used to have a unique identifier for every
     * state in the state machine.
     */
    typedef enum
    {
        STATE_UNKOWN = 0,			///< Unknown state
        STATE_INITIAL = 1,			///< Initial state
        STATE_ROOT = 2				///< State where to wait for further events
    } eMainState;

    eMainState _currentState;		///< Attribute indicating currently active state
};

} // namespace app

#endif // JOYSTICKAPPLICATION_H

