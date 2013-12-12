#include "Credits.hpp"

#include <Tank/System/Game.hpp>
#include <Tank/System/Keyboard.hpp>
#include "Resources.hpp"

Credits::Credits()
{
    using Key = tank::Key;
    using kbd = tank::Keyboard;

    makeEntity<tank::Entity>(tank::Vectorf{})->makeGraphic<tank::Image>(res::credits);
    connect(kbd::KeyPress(Key::Space) or kbd::KeyPress(Key::Return) or 
            kbd::KeyPress(Key::Right) or kbd::KeyPress(Key::SemiColon) or 
            kbd::KeyPress(Key::A) or kbd::KeyPress(Key::Left) or
            kbd::KeyPress(Key::Escape),
            [](){tank::Game::popWorld();});
}
