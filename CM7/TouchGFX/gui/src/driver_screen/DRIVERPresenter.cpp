#include <gui/driver_screen/DRIVERView.hpp>
#include <gui/driver_screen/DRIVERPresenter.hpp>

DRIVERPresenter::DRIVERPresenter(DRIVERView& v)
    : view(v)
{

}

void DRIVERPresenter::activate()
{

}

void DRIVERPresenter::deactivate()
{

}

void DRIVERPresenter::updateTick(void) {
	view.updateTick();
}
