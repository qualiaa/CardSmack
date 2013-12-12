#include "Tutorial.hpp"

#include <Tank/System/Game.hpp>
#include <Tank/System/Keyboard.hpp>
#include "Resources.hpp"

Tutorial::Tutorial()
{
    using kbd = tank::Keyboard;
    using key = tank::Key;

    finished_ = false;


    tut1_ = makeEntity<tank::Entity>(tank::Vectorf{});
    tut1_->makeGraphic<tank::Image>(res::tut1);
    connect(kbd::KeyPress(key::Space) or kbd::KeyPress(key::Return) or
            kbd::KeyPress(key::Right) or kbd::KeyPress(key::SemiColon),
            [this]{nextPage();});

    connect(kbd::KeyPress(key::A) or kbd::KeyPress(key::Left) or
            kbd::KeyPress(key::Escape),
            [this]{previousPage();});

}

void Tutorial::nextPage()
{
    if (finished_)
    {
        tank::Game::popWorld();
    }
    else
    {
        tut1_->remove();
        tut2_ = makeEntity<tank::Entity>(tank::Vectorf{});
        tut2_->makeGraphic<tank::Image>(res::tut2);
        finished_ = true;
    }
}

void Tutorial::previousPage()
{
    if (not finished_)
    {
        tank::Game::popWorld();
    }
    else
    {
        tut2_->remove();
        tut1_ = makeEntity<tank::Entity>(tank::Vectorf{});
        tut1_->makeGraphic<tank::Image>(res::tut1);
        finished_ = false;
    }
}
