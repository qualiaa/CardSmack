#include "Hand.hpp"

#include <iostream>

Hand::Hand(Deck const& deck, Field& field)
    : deck_(deck)
    , field_(field)
{
    for (int i = 0; i < cards_.size(); ++i)
    {
        drawCard(i);
    }
}

Card const* Hand::getCard(unsigned int slot)
{
    return cards_[slot];
}

Card const* Hand::releaseCard(unsigned int slot)
{
    Card const* temp = cards_[slot];
    drawCard(slot);

    return temp;
}

void Hand::drawCard(unsigned int slot)
{
    cards_[slot] = deck_.drawCard();
    std::cout << "Drew card: " << cards_[slot]->getName() << std::endl;
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
