#ifndef STACK_5_POPUP_HPP
#define STACK_5_POPUP_HPP

#include <gui_generated/containers/STACK_5_PopUpBase.hpp>

class STACK_5_PopUp : public STACK_5_PopUpBase
{
public:
    STACK_5_PopUp();
    virtual ~STACK_5_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_5_POPUP_HPP
