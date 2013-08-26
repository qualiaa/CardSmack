#include "Hand.hpp"

#include <iostream>

#include "Resources.hpp"
#include "Settings.hpp"
#include "Summoner.hpp"

tank::Image HandGUI::cardInactive(res::cardInactive);

Hand::Hand(Deck const& deck, Field& field)
    : deck_(deck)
{
    for (unsigned int i = 0; i < cards_.size(); ++i)
    {
        drawCard(i);
    }
}

Card const* Hand::getCard(unsigned int slot) const
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
}

void Hand::shiftLeft()
{
    std::rotate(cards_.begin(), cards_.begin() + 1, cards_.end());
}

void Hand::shiftRight()
{
    std::rotate(cards_.begin(), cards_.end() - 2, cards_.end());
}

HandGUI::HandGUI(Summoner* summoner)
    : Entity(tank::Vectorf { 0.f, 0.f })
    , summoner_(summoner)
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        cardSlots_[i].setPos({getPos().x + settings::cardSpace * i,
                              getPos().y});
    }
}

void HandGUI::update()
{
    std::cout << "Updating HandGUI" << std::endl;

    for (unsigned int i = 0; i < 6; ++i)
    {
        if (cardSlots_[i].getCard() != summoner_->getHand().getCard(i))
        {
            cardSlots_[i].setCard(summoner_->getHand().getCard(i));
        }
    }
    std::cout << "Done updating" << std::endl;
}

void HandGUI::draw(tank::Vectorf cam)
{
    std::cout << "Drawing HandGUI" << std::endl;
    for (unsigned int i = 0; i < 6; ++i)
    {
        std::cout << "Drawing slot " << i << std::endl;
        cardSlots_[i].draw(cam);
        if (summoner_->getField().isActive(i))
        {
            cardInactive.draw({0.f, 0.f});
        }
    }
    std::cout << "Done drawing" << std::endl;
}
