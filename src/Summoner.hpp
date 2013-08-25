#ifndef SUMMONER_HPP
#define SUMMONER_HPP

#include <array>
#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "Field.hpp"
#include "Hand.hpp"

class MainState;

class Summoner
{
public:
    Summoner(Deck const& deck, MainState& game);

    virtual void update(bool myTurn) = 0;
    void beginTurn();
    void endTurn();
protected:
    Hand hand_;
    Field field_;
    tank::Timer turnTimer_;
    MainState& game_;
};

class AI : public Summoner
{
public:
    AI(Deck const& deck, MainState& game): Summoner(deck,game) {}
    virtual void update(bool myTurn) override;
};

#endif /* SUMMONER_HPP */
