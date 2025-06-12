#include <gui/safety_screen/SAFETYView.hpp>
#include <gui/safety_screen/SAFETYPresenter.hpp>

SAFETYPresenter::SAFETYPresenter(SAFETYView& v)
    : view(v)
{

}

void SAFETYPresenter::activate()
{

}

void SAFETYPresenter::deactivate()
{

}

void SAFETYPresenter::updateTick(void) {
	view.updateTick();
}
