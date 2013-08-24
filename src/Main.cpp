#include <Tank/System/Game.hpp>
#include "MainState.hpp"

int main()
{
    if(tank::Game::initialize({800,600}))
    {
        tank::Game::makeState<MainState>();
        tank::Game::window()->setCaption("Card Smack");
        tank::Game::run();
    }
}
