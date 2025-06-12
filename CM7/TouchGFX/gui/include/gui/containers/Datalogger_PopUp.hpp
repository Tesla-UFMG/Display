#ifndef DATALOGGER_POPUP_HPP
#define DATALOGGER_POPUP_HPP

#include <gui_generated/containers/Datalogger_PopUpBase.hpp>

class Datalogger_PopUp : public Datalogger_PopUpBase
{
public:
    Datalogger_PopUp();
    virtual ~Datalogger_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // DATALOGGER_POPUP_HPP
