#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <Tank/Graphics/Image.hpp>

struct res
{
    struct abilities
    {
        static const tank::Image blockLeft;
        static const tank::Image blockRight;
        static const tank::Image directDamage;
        static const tank::Image doubleDamage;
        static const tank::Image healthGain;
        static const tank::Image manaGain;
    };

    static const tank::Image powerIcon;
    static const tank::Image costIcon;
};

#endif /* RESOURCES_HPP */
