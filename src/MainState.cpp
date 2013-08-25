#include "MainState.hpp"

#include <iostream>
#include <boost/filesystem.hpp>
#include "Settings.hpp"
#include "Player.hpp"

MainState::MainState()
{
    for (boost::filesystem::directory_iterator deckIter("res/decks");
         deckIter != boost::filesystem::directory_iterator();
         ++deckIter)
    {
        decks_.push_back(deckIter->path().string());
    }

    summoners_[0].reset(new Player(decks_.back(), *this));
    summoners_[1].reset(new AI(decks_.back(), *this));

    turnTimer_.start();
}

void MainState::endTurn()
{
    std::cout << "Turn over" << std::endl;
    summoners_[currentPlayer_]->endTurn();
    currentPlayer_ = not currentPlayer_;
    summoners_[currentPlayer_]->beginTurn();
}

void MainState::update()
{
    summoners_[currentPlayer_]->update(true);
    summoners_[not currentPlayer_]->update(false);

    if (turnTimer_.getTicks() > 1000 * settings::turnTime)
    {
        endTurn();
        turnTimer_.start();
    }

    tank::State::update();
}
