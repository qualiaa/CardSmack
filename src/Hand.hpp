#ifndef HAND_HPP
#define HAND_HPP

#include <array>
#include "Deck.hpp"
#include "Field.hpp"

class Hand
{
public:
    Hand(Deck const& deck_, Field& field);

    Card* getCard(unsigned int slot);
    Card* releaseCard(unsigned int slot);

    void shiftRight();
    void shiftLeft();
    void update();
private:
    Deck const& deck_;
    Field& field_;
    std::array<Card*, 6> cards_;
};

#endif
