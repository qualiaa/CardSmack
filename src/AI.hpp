#ifndef AI_HPP
#define AI_HPP

#include "Summoner.hpp"

class AI : public Summoner
{
public:
    AI(Deck const* deck, MainState& game): Summoner(deck,game) {}
private:
    virtual void gameLogic(unsigned int turnTime) override;

    tank::Timer moveTimer_;
};

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

#endif /* AI_HPP */
