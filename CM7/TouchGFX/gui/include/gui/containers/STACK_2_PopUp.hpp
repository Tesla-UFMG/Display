#ifndef STACK_2_POPUP_HPP
#define STACK_2_POPUP_HPP

#include <gui_generated/containers/STACK_2_PopUpBase.hpp>

class STACK_2_PopUp : public STACK_2_PopUpBase
{
public:
    STACK_2_PopUp();
    virtual ~STACK_2_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_2_POPUP_HPP
