#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <vector>
#include <memory>
#include <Tank/System/World.hpp>
#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "Summoner.hpp"

class MainState : public tank::World
{
public:
    MainState();

    void endTurn();

    virtual void update() override;
private:
    void resolveAttacks();

    bool currentPlayer_;
    tank::Timer turnTimer_;

    std::array<std::unique_ptr<Summoner>,2> summoners_;
    std::vector<std::unique_ptr<Deck>> decks_;
};

#endif /* MAINSTATE_HPP */
