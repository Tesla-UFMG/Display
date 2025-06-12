#ifndef STACK_3_POPUP_HPP
#define STACK_3_POPUP_HPP

#include <gui_generated/containers/STACK_3_PopUpBase.hpp>

class STACK_3_PopUp : public STACK_3_PopUpBase
{
public:
    STACK_3_PopUp();
    virtual ~STACK_3_PopUp() {}
    virtual void updateTick(void);

    virtual void initialize();
protected:
};

#endif // STACK_3_POPUP_HPP
