#ifndef MAINSTATE_HPP
#define MAINSTATE_HPP

#include <vector>
#include <memory>
#include <Tank/System/State.hpp>
#include "Deck.hpp"
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

    std::vector<Deck> decks_;
};

#endif /* MAINSTATE_HPP */
