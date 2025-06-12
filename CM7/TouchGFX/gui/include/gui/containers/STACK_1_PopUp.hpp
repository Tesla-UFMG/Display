#ifndef STACK_1_POPUP_HPP
#define STACK_1_POPUP_HPP

#include <gui_generated/containers/STACK_1_PopUpBase.hpp>

class STACK_1_PopUp : public STACK_1_PopUpBase
{
public:
    STACK_1_PopUp();
    virtual ~STACK_1_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_1_POPUP_HPP
