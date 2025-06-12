#ifndef ECU_POPUP_HPP
#define ECU_POPUP_HPP

#include <gui_generated/containers/ECU_PopUpBase.hpp>

class ECU_PopUp : public ECU_PopUpBase
{
public:
    ECU_PopUp();
    virtual ~ECU_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // ECU_POPUP_HPP
