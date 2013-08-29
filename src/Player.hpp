#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Summoner.hpp"

class Player : public Summoner
{
public:
    Player(std::unique_ptr<Deck> const& deck, MainState& game);

private:
    virtual void gameLogic(unsigned int turnTime) override;
    inline void makeAction(unsigned int slot);
};

#endif /* PLAYER_HPP */
