#ifndef FIELD_HPP
#define FIELD_HPP

#include "Deck.hpp"

class Field
{
public:
    Field();

    void removeCard(unsigned int slot);
    void setCard(Card*, unsigned int slot);
    Card* getCard(unsigned int slot) const;

    bool isTaken(unsigned int slot) const;
    void toggleAttack(unsigned int slot);
    bool isAttacking(unsigned int slot) const;
private:
    std::array<Card*, 6> cards_;
    std::array<bool, 6> attacking_;
};

#endif /* FIELD_HPP */
