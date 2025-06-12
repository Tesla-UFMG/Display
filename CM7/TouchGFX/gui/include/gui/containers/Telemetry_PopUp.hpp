#ifndef TELEMETRY_POPUP_HPP
#define TELEMETRY_POPUP_HPP

#include <gui_generated/containers/Telemetry_PopUpBase.hpp>

class Telemetry_PopUp : public Telemetry_PopUpBase
{
public:
    Telemetry_PopUp();
    virtual ~Telemetry_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // TELEMETRY_POPUP_HPP
