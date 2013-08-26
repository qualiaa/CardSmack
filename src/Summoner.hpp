#ifndef SUMMONER_HPP
#define SUMMONER_HPP

#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "Field.hpp"
#include "Hand.hpp"

class MainState;

class Summoner
{
public:
    Summoner(Deck const& deck, MainState& game);

    void update(bool myTurn);

    void damage (unsigned int deeps);
    void heal (unsigned int antideeps);

    unsigned int getLife() const { return life_; }
    unsigned int getMana() const { return mana_; }
    unsigned int getManaTicks() const { return manaTimer_.getTicks(); }

    Field& getField() { return field_; }
    Hand& getHand() { return hand_; }

    std::string name;

    void beginTurn();
    void endTurn();
protected:
    virtual void gameLogic(bool myTurn) = 0;
    void play(unsigned int slot);
    void shiftHandLeft();
    void shiftHandRight();

    unsigned int life_;
    unsigned int mana_;
    Field field_;
    Hand hand_;
    tank::Timer manaTimer_;
    MainState& game_;
};

class AI : public Summoner
{
public:
    AI(Deck const& deck, MainState& game): Summoner(deck,game) {}
private:
    virtual void gameLogic(bool myTurn) override;

    tank::Timer moveTimer_;
};

#endif /* SUMMONER_HPP */
