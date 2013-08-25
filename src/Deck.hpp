#ifndef DECK_HPP
#define DECK_HPP

#include <string>
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
    unsigned int getStrength() { return strength_; }
    tank::Image& getImage() { return image_; }
    std::string getName() { return name_; }
    Ability getAbility() { return ability_; }
private:
    unsigned int rarity_;
    unsigned int strength_;
    tank::Image image_;
    std::string name_;
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
