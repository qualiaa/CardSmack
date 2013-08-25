#include "Summoner.hpp"

#include <algorithm>
#include <iostream>
#include "Settings.hpp"
#include "MainState.hpp"

Summoner::Summoner(Deck const& deck, MainState& game)
    : life_(settings::maxLife)
    , mana_(settings::maxMana)
    , hand_(deck, field_)
    , game_(game)
{
    manaTimer_.start();
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

    if (manaTimer_.getTicks() > 1000 * settings::manaRegen / settings::maxMana)
    {
        manaTimer_.start();
        if (mana_ != settings::maxMana)
        {
            ++mana_;
        }
    }

    gameLogic(myTurn);
}
