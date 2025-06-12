#ifndef DRIVERPRESENTER_HPP
#define DRIVERPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DRIVERView;

class DRIVERPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DRIVERPresenter(DRIVERView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~DRIVERPresenter() {}

    virtual void updateTick(void);
private:
    DRIVERPresenter();

    DRIVERView& view;
};

#endif // DRIVERPRESENTER_HPP
