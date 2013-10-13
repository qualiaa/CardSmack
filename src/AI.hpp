#ifndef AI_HPP
#define AI_HPP

#include "Summoner.hpp"

class AI : public Summoner
{
public:
    AI(std::unique_ptr<Deck> const&, MainState& game);
private:
    virtual void gameLogic(unsigned int turnTime) override;

    void tick(unsigned int turnTime);

    tank::Timer moveTimer_;
};

#endif /* AI_HPP */
