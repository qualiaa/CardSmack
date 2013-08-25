#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <memory>
#include <Tank/System/State.hpp>
#include "Summoner.hpp"

class MainState : public tank::State
{
public:
    MainState();
    void endTurn();

    virtual void update() override;
private:
    std::unique_ptr<Summoner> summoners_[2];
    bool currentPlayer_;

    Deck testDeck;
};

#endif /* MAINSTATE_HPP */
