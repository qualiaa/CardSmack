#include <cstdlib>
#include <ctime>
#include <Tank/System/Game.hpp>
#include "MainState.hpp"

int main()
{
    std::srand(std::time(NULL));
    if(tank::Game::initialize({960,720}))
    {
        tank::Game::makeState<MainState>();
        tank::Game::window()->setCaption("Card Smack");
        tank::Game::run();
    }
}
