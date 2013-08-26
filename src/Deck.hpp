#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include "Card.hpp"

class Deck
{
public:
    Deck(std::string filepath);
    Card const* drawCard() const;
private:
    unsigned int relChanceTotal_;
    std::vector<Card> cards_;
};

#endif /* DECK_HPP */
