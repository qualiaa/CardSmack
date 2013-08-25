#include "Field.hpp"

Field::Field()
{
    //std::fill(cards_.begin(), cards_.end(), nullptr);
    cards_ = {};
    attacking_ = {};
}

bool Field::isTaken(unsigned int slot) const
{
    return cards_[slot];
}

void Field::toggleAttack(unsigned int slot)
{
    if (cards_[slot])
    {
        attacking_[slot] = not attacking_[slot];
    }
}

bool Field::isAttacking(unsigned int slot) const
{
    if (cards_[slot])
    {
        return attacking_[slot];
    }

    return false;
}

Card* Field::getCard(unsigned int slot) const
{
    return cards_[slot];
}

void Field::removeCard(unsigned int slot)
{
    cards_[slot] = nullptr;
    attacking_[slot] = false;
}

void Field::setCard(Card* card, unsigned int slot)
{
    cards_[slot] = card;
}
