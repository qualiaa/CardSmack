#ifndef AI_HPP
#define AI_HPP

#include "Summoner.hpp"

class AI : public Summoner
{
public:
    AI(Deck const* deck, MainState& game);
private:
    virtual void gameLogic(unsigned int turnTime) override;

    void tick(unsigned int turnTime);

    tank::Timer moveTimer_;
};

#endif /* AI_HPP */
