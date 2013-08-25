#ifndef HAND_HPP
#define HAND_HPP

#include <array>
#include "Deck.hpp"
#include "Field.hpp"

class Hand
{
public:
    Hand(Deck const& deck_, Field& field);

    Card const* getCard(unsigned int slot);
    Card const* releaseCard(unsigned int slot);

    inline void drawCard(unsigned int slot);

    void shiftRight();
    void shiftLeft();
    void update();
private:
    Deck const& deck_;
    Field& field_;
    std::array<Card const*, 6> cards_;
};

#endif
