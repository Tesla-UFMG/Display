#include <gui/animation_screen/ANIMATIONView.hpp>

#define TIME_TRANSITION 15U

ANIMATIONView::ANIMATIONView()
{

}

void ANIMATIONView::setupScreen()
{
    ANIMATIONViewBase::setupScreen();
}

void ANIMATIONView::tearDownScreen()
{
    ANIMATIONViewBase::tearDownScreen();
}

void ANIMATIONView::TransitionEnd_Animation()
{
    FRONTGROUND.clearFadeAnimationEndedAction();
    FRONTGROUND.startFadeAnimation(255, TIME_TRANSITION, touchgfx::EasingEquations::linearEaseIn);
}
