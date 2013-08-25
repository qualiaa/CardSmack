#include "MainState.hpp"

#include "Player.hpp"

MainState::MainState()
    : testDeck("res/decks/testdeck")
{
    summoners_[0].reset(new Player(testDeck, *this));
    summoners_[1].reset(new AI(testDeck, *this));
}

void MainState::endTurn()
{
    summoners_[currentPlayer_]->endTurn();
    currentPlayer_ = not currentPlayer_;
    summoners_[currentPlayer_]->beginTurn();
}

void MainState::update()
{
    summoners_[currentPlayer_]->update(true);
    summoners_[not currentPlayer_]->update(false);

    tank::State::update();
}
