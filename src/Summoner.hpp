#ifndef SUMMONER_HPP
#define SUMMONER_HPP

#include "Card.hpp"

class Hand
{
public:
    Hand();
    void toggle(unsigned int slot);
    void play(unsigned int slot);
};

class Field
{
public:
    Field();
};

class Summoner
{
public:
    Summoner();
private:
    Hand hand_;
    Field field_;
};

#endif /* SUMMONER_HPP */
