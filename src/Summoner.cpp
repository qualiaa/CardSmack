#include "Summoner.hpp"

#include <algorithm>
#include <iostream>
#include "Settings.hpp"
#include "MainState.hpp"
#include "Deck.hpp"
#include "Card.hpp"

Summoner::Summoner(Deck const* deck, MainState& game)
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

void Summoner::update(bool myTurn)
{
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

    gameLogic(myTurn);
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

    std::cout << "[Slot " << slot << "] "
              << "Played " << card->getName()
              << " for " << manaCost << " mana" << std::endl;

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
}

void AI::gameLogic(bool myTurn)
{
    if (myTurn)
    {
        if (not moveTimer_.isStarted())
        {
            moveTimer_.start();
        }
        else if (moveTimer_.getTicks() > 4500)
        {
            moveTimer_.stop();
            game_.endTurn();
        }
        else if (moveTimer_.getTicks() > 2500)
        {
            play(0);
        }
    }
}
