#ifndef HAND_HPP
#define HAND_HPP

#include <array>
#include "Deck.hpp"
#include "Field.hpp"
#include "CardOverlay.hpp"

class Summoner;

class Hand
{
public:
    Hand(std::unique_ptr<Deck> const&, Field& field);

    Card const* getCard(unsigned int slot) const;
    inline void drawCard(unsigned int slot);

    bool play(unsigned int slot);

    void shiftRight();
    void shiftLeft();
private:
    std::unique_ptr<Deck> const& deck_;
    Field& field_;
    std::array<Card const*, 6> cards_;
};

class HandGUI : public tank::Entity
{
public:
    HandGUI(tank::Vectorf pos, std::unique_ptr<Summoner> const&);

    virtual void update() override;
    virtual void draw(tank::Camera const&) override;
private:
    CardOverlay overlay_;
    std::unique_ptr<Summoner> const& summoner_;

    std::array<CardSlot, 6> cardSlots_;

};

#endif
