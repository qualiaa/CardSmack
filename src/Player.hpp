#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Summoner.hpp"

class Player : public Summoner
{
public:
    Player(Deck const& deck, MainState& game);

private:
    virtual void gameLogic(bool myTurn) override;
    inline void makeAction(unsigned int slot);
};

#endif /* PLAYER_HPP */
