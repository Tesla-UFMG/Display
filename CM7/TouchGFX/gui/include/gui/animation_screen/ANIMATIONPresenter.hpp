#ifndef ANIMATIONPRESENTER_HPP
#define ANIMATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ANIMATIONView;

class ANIMATIONPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ANIMATIONPresenter(ANIMATIONView& v);

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

    virtual ~ANIMATIONPresenter() {}

private:
    ANIMATIONPresenter();

    ANIMATIONView& view;
};

#endif // ANIMATIONPRESENTER_HPP
