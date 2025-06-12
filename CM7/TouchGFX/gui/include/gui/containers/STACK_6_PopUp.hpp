#ifndef STACK_6_POPUP_HPP
#define STACK_6_POPUP_HPP

#include <gui_generated/containers/STACK_6_PopUpBase.hpp>

class STACK_6_PopUp : public STACK_6_PopUpBase
{
public:
    STACK_6_PopUp();
    virtual ~STACK_6_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_6_POPUP_HPP
