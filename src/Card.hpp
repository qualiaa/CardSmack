#ifndef CARD_HPP
#define CARD_HPP

#include <Tank/Utility/Vector.hpp>
#include <Tank/Graphics/Image.hpp>
#include "ZoomHack.hpp"

enum Ability
{
    None,
    Placeholder1,
    Placeholder2,
    Placeholder3,
    Placeholder4,
    Placeholder5,
    Placeholder6,
    Placeholder7,
    Placeholder8,
    Placeholder9,
    Placeholder10,
    AbilityCount
};

class Deck;

class Card
{
public:
    Card(std::string xmlPath, std::string imagePath, Deck const& deck);

    unsigned int getStrength() const { return strength_; }
    unsigned int getCost() const { return cost_; }
    unsigned int getRarity() const { return rarity_; }
    unsigned int getRelativeChance() const { return relativeChance_; }
    tank::Image const& getImage() const { return image_; }
    std::string getName() const { return name_; }
    Ability getAbility() const { return ability_; }

    static const double rarityToChance[4];

    Deck const& deck;
private:
    std::string name_;
    tank::Image image_;
    unsigned int strength_;
    unsigned int cost_;
    unsigned int rarity_;
    unsigned int relativeChance_;
    Ability ability_;
};

class CardGUI : public ZoomHack
{
public:
    CardGUI(tank::Vectorf pos, Card const* card);
private:
};

#endif /* CARD_HPP */
