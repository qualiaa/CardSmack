#ifndef HAND_HPP
#define HAND_HPP

#include <array>
#include "Deck.hpp"
#include "Field.hpp"

class Summoner;

class Hand
{
public:
    Hand(Deck const* deck_, Field& field);

    Card const* getCard(unsigned int slot) const;
    Card const* releaseCard(unsigned int slot);

    inline void drawCard(unsigned int slot);

    void shiftRight();
    void shiftLeft();
private:
    Deck const* deck_;
    std::array<Card const*, 6> cards_;
};

class HandGUI : public tank::Entity
{
public:
    HandGUI(Summoner*);

    virtual void update() override;
    virtual void draw(tank::Vectorf cam) override;
private:
    Summoner* summoner_;

    std::array<CardSlot, 6> cardSlots_;

};

class InvalidSlot : public ZoomHack
{
public:
    InvalidSlot(tank::Vectorf pos);
};

#endif
