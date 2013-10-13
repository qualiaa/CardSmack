#include "Credits.hpp"

#include <Tank/System/Game.hpp>
#include "Resources.hpp"

Credits::Credits()
{
    makeEntity<tank::Entity>(tank::Vectorf{})->makeGraphic<tank::Image>(res::credits);
    eventHandler.define("next",
        {
            tank::Key::Space, tank::Key::Return, tank::Key::Right,
            tank::Key::SemiColon, tank::Key::A, tank::Key::Left,
            tank::Key::Escape
        });
}

void Credits::update()
{
    if (eventHandler.check("next"))
    {
        tank::Game::popState();
    }

    tank::State::update();
}
