#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <Tank/System/EventHandler.hpp>
#include "Summoner.hpp"

class Player : public Summoner
{
    using Connection = tank::observing_ptr<tank::EventHandler::Connection>;

public:
    Player(std::unique_ptr<Deck> const& deck, MainState& game);
private:
    inline void makeAction(unsigned int slot);
};

#endif /* PLAYER_HPP */
