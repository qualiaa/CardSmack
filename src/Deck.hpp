#ifndef DECK_HPP
#define DECK_HPP

#include <string>
#include <cmath>
#include <Tank/Graphics/Image.hpp>

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

class Card
{
public:
    Card(std::string xmlPath, std::string imagePath);

    unsigned int getStrength() const { return strength_; }
    unsigned int getCost() const { return cost_; }
    unsigned int getRelativeChance() const { return relativeChance_; }
    tank::Image const& getImage() const { return image_; }
    std::string getName() const { return name_; }
    Ability getAbility() const { return ability_; }

    static const double rarityToChance[4];
private:
    std::string name_;
    tank::Image image_;
    unsigned int strength_;
    unsigned int cost_;
    unsigned int relativeChance_;
    Ability ability_;
};

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
