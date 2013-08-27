#include "Tutorial.hpp"

#include <Tank/System/Game.hpp>
#include "Resources.hpp"

Tutorial::Tutorial()
{
    finished_ = false;


    tut1_ = makeEntity<tank::Entity>(tank::Vectorf{});
    tut1_->makeGraphic<tank::Image>(res::tut1);
    eventHandler.define("next", { tank::Key::Space, tank::Key::Return, tank::Key::Right, tank::Key::SemiColon });
    eventHandler.define("back", { tank::Key::A, tank::Key::Left, tank::Key::Escape });

}

void Tutorial::update()
{
    if ((eventHandler.check("next") and finished_) or
        (eventHandler.check("back") and not finished_))
    {
        tank::Game::popState();
    }
    else if (eventHandler.check("next"))
    {
        tut1_->remove();
        tut2_ = makeEntity<tank::Entity>(tank::Vectorf{});
        tut2_->makeGraphic<tank::Image>(res::tut2);
        finished_ = true;
    }
    else if (eventHandler.check("back"))
    {
        tut2_->remove();
        tut1_ = makeEntity<tank::Entity>(tank::Vectorf{});
        tut1_->makeGraphic<tank::Image>(res::tut1);
        finished_ = false;
    }

    tank::State::update();
}
