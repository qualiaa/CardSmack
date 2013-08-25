#include "Hand.hpp"

Hand::Hand(Deck const& deck, Field& field)
    : deck_(deck)
    , field_(field)
{
    for (auto card : cards_)
    {
        card = deck_.drawCard();
    }
}

Card* Hand::getCard(unsigned int slot)
{
    return cards_[slot];
}

Card* Hand::releaseCard(unsigned int slot)
{
    Card* temp = cards_[slot];
    cards_[slot] = deck_.drawCard();

    return temp;
}

void Hand::shiftRight()
{
    // TODO: Test
    std::rotate(cards_.begin(), cards_.end() - 2, cards_.end());
}

void Hand::shiftLeft()
{
    std::rotate(cards_.begin(), cards_.begin() + 1, cards_.end());
} 
