#include <gui/debug_screen/DEBUGView.hpp>
#include <gui/debug_screen/DEBUGPresenter.hpp>

DEBUGPresenter::DEBUGPresenter(DEBUGView& v)
    : view(v)
{

}

void DEBUGPresenter::activate()
{

}

void DEBUGPresenter::deactivate()
{

}

void DEBUGPresenter::updateTick(void) {
	view.updateTick();
}
