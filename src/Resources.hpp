#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <Tank/Graphics/Image.hpp>
#include "Card.hpp"

struct res
{
    static const tank::Image abilities[Ability::AbilityCount];

    static const tank::Image powerIcon;
    static const tank::Image costIcon;
};

#endif /* RESOURCES_HPP */
