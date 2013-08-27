#include "AI.hpp"

AI::AI(Deck const* deck, MainState& game)
    : Summoner(deck,game) {}

void AI::gameLogic(unsigned int turnTime)
{
    if (turnTime)
    {
        if (not moveTimer_.isStarted())
        {
            moveTimer_.start();
        }
        else if (moveTimer_.getTicks() > 1500)
        {
            tick(turnTime);
            moveTimer_.stop();
        }
    }
}

void AI::tick(unsigned int turnTime)
{
    unsigned int mostPowerful = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (not field_.isActive(i))
        {
            if (hand_.getCard(i)->getStrength() >
                hand_.getCard(mostPowerful)->getStrength())
            {
                mostPowerful = i;
            }
        }

    }

    play(mostPowerful);
}
