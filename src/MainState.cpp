#include "MainState.hpp"

#include <boost/filesystem.hpp>
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
