#ifndef SUMMONER_HPP
#define SUMMONER_HPP

#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "Field.hpp"
#include "Hand.hpp"

class MainState;

class Summoner
{
public:
    Summoner(Deck const& deck, MainState& game);

    void update(bool myTurn);

    void beginTurn();
    void endTurn();
protected:
    virtual void gameLogic(bool myTurn) = 0;
    Hand hand_;
    Field field_;
    tank::Timer turnTimer_;
    MainState& game_;
};

class AI : public Summoner
{
public:
    AI(Deck const& deck, MainState& game): Summoner(deck,game) {}
private:
    virtual void gameLogic(bool myTurn) override {}
};

#endif /* SUMMONER_HPP */
