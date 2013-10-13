#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <Tank/Graphics/Image.hpp>
#include "Card.hpp"

class Deck
{
public:
    Deck(std::string filepath);
    Card const* drawCard() const;

    tank::Image rarity[4];
    tank::Image backing;
private:
    unsigned int relChanceTotal_;
    std::vector<Card> cards_;
};

#endif /* DECK_HPP */
