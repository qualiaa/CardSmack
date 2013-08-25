#ifndef DECK_HPP
#define DECK_HPP

#include <string>
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

    unsigned int getRarity() { return rarity_; }
    unsigned int getStrength() { return strength_; }
    tank::Image& getImage() { return image_; }
    std::string getName() { return name_; }
    Ability getAbility() { return ability_; }
private:
    std::string name_;
    tank::Image image_;
    unsigned int strength_;
    unsigned int cost_;
    unsigned int rarity_;
    Ability ability_;
};

class Deck
{
public:
    Deck(std::string filepath);
    Card* drawCard() const;
private:
    std::vector<Card> cards_;
};

#endif /* DECK_HPP */
