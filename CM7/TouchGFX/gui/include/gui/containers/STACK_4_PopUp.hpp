#ifndef STACK_4_POPUP_HPP
#define STACK_4_POPUP_HPP

#include <gui_generated/containers/STACK_4_PopUpBase.hpp>

class STACK_4_PopUp : public STACK_4_PopUpBase
{
public:
    STACK_4_PopUp();
    virtual ~STACK_4_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_4_POPUP_HPP
