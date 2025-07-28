#include <gui/animation_screen/ANIMATIONView.hpp>

extern bool bottom_state;
bool ANIMATION_page_Interlock = false;
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

	ANIMATION_page_Interlock = true;
}

void ANIMATIONView::updateTick(void) {
#ifndef SIMULATOR
	if (bottom_state && !ANIMATION_page_Interlock)
		application().gotoDRIVERScreenNoTransition();
	else if (!bottom_state)
		ANIMATION_page_Interlock = false;
#endif
}
