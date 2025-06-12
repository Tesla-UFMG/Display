#ifndef ANIMATIONVIEW_HPP
#define ANIMATIONVIEW_HPP

#include <gui_generated/animation_screen/ANIMATIONViewBase.hpp>
#include <gui/animation_screen/ANIMATIONPresenter.hpp>

class ANIMATIONView : public ANIMATIONViewBase
{
public:
    ANIMATIONView();
    virtual ~ANIMATIONView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void TransitionEnd_Animation();
protected:
};

#endif // ANIMATIONVIEW_HPP
