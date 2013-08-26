#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <vector>
#include <memory>
#include <Tank/System/State.hpp>
#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "Summoner.hpp"

class MainState : public tank::State
{
public:
    MainState();
    virtual ~MainState();

    void endTurn();

    virtual void update() override;
private:
    void resolveAttacks();

    std::unique_ptr<Summoner> summoners_[2];
    bool currentPlayer_;
    tank::Timer turnTimer_;

    std::vector<Deck*> decks_;
};

#endif /* MAINSTATE_HPP */
