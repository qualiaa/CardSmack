#include "AI.hpp"

void AI::gameLogic(unsigned int turnTime)
{
    if (turnTime)
    {
        if (not moveTimer_.isStarted())
        {
            moveTimer_.start();
        }
        else if (moveTimer_.getTicks() > 4500)
        {
            moveTimer_.stop();
            game_.endTurn();
        }
        else if (moveTimer_.getTicks() > 2500)
        {
            play(0);
        }
    }
}
