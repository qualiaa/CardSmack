#include "MenuState.hpp"

MenuState::MenuState()
{
    makeEntity<tank::Entity>(tank::Vectorf{})->makeGraphic<tank::Image>(res::menuScreen);
}
