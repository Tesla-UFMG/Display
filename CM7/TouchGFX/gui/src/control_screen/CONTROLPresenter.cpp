#include <gui/control_screen/CONTROLView.hpp>
#include <gui/control_screen/CONTROLPresenter.hpp>

CONTROLPresenter::CONTROLPresenter(CONTROLView& v)
    : view(v)
{

}

void CONTROLPresenter::activate()
{

}

void CONTROLPresenter::deactivate()
{

}

void CONTROLPresenter::updateTick(void) {
	view.updateTick();
}
