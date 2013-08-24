#ifndef CARD_HPP
#define CARD_HPP

#include <Tank/Graphics/Image.hpp>

enum class Ability
{
    None,
    AbilityCount
};

class Card
{
public:
    Card(std::string file);

    unsigned int getRarity() { return rarity_; }
    unsigned int getStrength();
private:
    unsigned int rarity_;
    unsigned int strength_;
    tank::Image image_;
    std::string name_;
    Ability ability_;
}

#endif /* CARD_HPP */
