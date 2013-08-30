#include "Summoner.hpp"

#include <algorithm>
#include <Tank/System/Game.hpp>
#include "Settings.hpp"
#include "MainState.hpp"
#include "Deck.hpp"
#include "Card.hpp"

Summoner::Summoner(std::unique_ptr<Deck> const& deck, MainState& game)
    : life_(settings::maxLife)
    , time_(0)
    , mana_(settings::maxMana)
    , hand_(deck, field_)
    , game_(game)
{
    manaTimer_.start();
}

void Summoner::endTurn()
{
    game_.endTurn();
}

void Summoner::damage(unsigned int damage)
{
    if (damage > life_)
    {
        life_ = 0;
    }
    else
    {
        life_ -= damage;
    }
}

void Summoner::heal(unsigned int heal)
{
    life_ += heal;
    if (life_ > settings::maxLife)
    {
        life_ = settings::maxLife;
    }
}

void Summoner::update(unsigned int turnTime)
{
    time_ = turnTime;

    field_.update();

    if (mana_ < settings::maxMana and not manaTimer_.isStarted())
    {
        manaTimer_.start();
    }
    else if (mana_ < settings::maxMana and
             manaTimer_.getTicks() >
             1000 * settings::manaRegen / settings::maxMana)
    {
        ++mana_;

        manaTimer_.stop();
    }
    else if (mana_ >= settings::maxMana)
    {
        manaTimer_.stop();
    }

    gameLogic(turnTime);
}

void Summoner::play(unsigned int slot)
{
    if (field_.isActive(slot))
    {
        return;
    }

    Card const* card = hand_.getCard(slot);
    unsigned int manaCost = card->getCost();
    if (manaCost > mana_)
    {
        return;
    }

    mana_ -= manaCost;
    field_.setCard(hand_.releaseCard(slot), slot);
}

void Summoner::shiftHandLeft()
{
    if (mana_ == 0)
    {
        return;
    }

    --mana_;
    hand_.shiftLeft();
}

void Summoner::shiftHandRight()
{
    if (mana_ == 0)
    {
        return;
    }

    --mana_;
    hand_.shiftRight();
}

void Summoner::toggleAttack(unsigned int slot)
{
    field_.toggleAttack(slot);
}
