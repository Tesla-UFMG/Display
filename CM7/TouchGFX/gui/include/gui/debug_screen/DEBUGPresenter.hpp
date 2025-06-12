#ifndef DEBUGPRESENTER_HPP
#define DEBUGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DEBUGView;

class DEBUGPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DEBUGPresenter(DEBUGView& v);

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

    virtual ~DEBUGPresenter() {}

    virtual void updateTick(void);

private:
    DEBUGPresenter();

    DEBUGView& view;
};

#endif // DEBUGPRESENTER_HPP
