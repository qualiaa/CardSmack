#include "Summoner.hpp"

#include <algorithm>
#include <iostream>
#include "Settings.hpp"
#include "MainState.hpp"

Summoner::Summoner(Deck const& deck, MainState& game)
    : hand_(deck, field_)
    , game_(game)
{
}

void Summoner::beginTurn()
{
}

void Summoner::endTurn()
{
}

void Summoner::update(bool myTurn)
{
    field_.update();

    gameLogic(myTurn);
}
