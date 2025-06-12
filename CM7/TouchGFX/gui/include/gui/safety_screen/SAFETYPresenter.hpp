#ifndef SAFETYPRESENTER_HPP
#define SAFETYPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SAFETYView;

class SAFETYPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SAFETYPresenter(SAFETYView &v);

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

    virtual ~SAFETYPresenter() {}

    virtual void updateTick(void);

private:
    SAFETYPresenter();

    SAFETYView &view;
};

#endif // SAFETYPRESENTER_HPP
