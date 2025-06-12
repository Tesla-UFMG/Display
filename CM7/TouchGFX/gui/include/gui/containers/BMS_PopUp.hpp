#ifndef BMS_POPUP_HPP
#define BMS_POPUP_HPP

#include <gui_generated/containers/BMS_PopUpBase.hpp>

class BMS_PopUp : public BMS_PopUpBase
{
public:
    BMS_PopUp();
    virtual ~BMS_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // BMS_POPUP_HPP
