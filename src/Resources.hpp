#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <Tank/Graphics/Image.hpp>
#include "Card.hpp"

struct res
{
    static const tank::Image abilities[Ability::AbilityCount];

    static const tank::Image powerIcon;
    static const tank::Image costIcon;
    static const tank::Image cardInactive;
    static const tank::Image playingField;
    static const tank::Image playerHealth;
    static const tank::Image playerTime;
    static const tank::Image playerMana;
    static const tank::Image enemyHealth;
    static const tank::Image health;
    static const tank::Image time;
    static const tank::Image mana;

    static const tank::Image menuScreen;
};

#endif /* RESOURCES_HPP */
