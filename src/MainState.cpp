#include "MainState.hpp"

#include <iostream>
#include <boost/filesystem.hpp>
#include <Tank/System/Game.hpp>
#include "Resources.hpp"
#include "Settings.hpp"
#include "Player.hpp"
#include "AI.hpp"
#include "HealthBar.hpp"
#include "ManaBar.hpp"
#include "TimeBar.hpp"

MainState::MainState()
{
    for (boost::filesystem::directory_iterator deckIter("res/decks");
         deckIter != boost::filesystem::directory_iterator();
         ++deckIter)
    {
        decks_.push_back(new Deck(deckIter->path().string()));
    }

    summoners_[0].reset(new Player(decks_.back(), *this));
    summoners_[1].reset(new AI(decks_.front(), *this));

    summoners_[0]->name = "Player";
    summoners_[1]->name = "AI";

    makeEntity<tank::Entity>(tank::Vectorf{})->
        makeGraphic<tank::Image>(res::playingField);
    makeEntity<HandGUI>(tank::Vectorf {56.f, 216.f }, summoners_[0].get());
    makeEntity<FieldGUI>(tank::Vectorf {56.f, 128.f},
                         summoners_[0]->getField(),
                         true);
    makeEntity<FieldGUI>(tank::Vectorf {56.f, 48.f},
                         summoners_[1]->getField(),
                         false);

    makeEntity<HealthBar>(summoners_[1].get(), false);
    makeEntity<HealthBar>(summoners_[0].get(), true);
    makeEntity<TimeBar>(summoners_[0].get());
    makeEntity<ManaBar>(summoners_[0].get());

    turnTimer_.start();

    eventHandler.define("quit", { tank::Key::Escape });
}

MainState::~MainState()
{
    while (not decks_.empty())
    {
        delete decks_.back();
        decks_.pop_back();
    }
}

void MainState::endTurn()
{
    resolveAttacks();
    currentPlayer_ = not currentPlayer_;

    for (auto& p : summoners_)
    {
        if (p->getLife() == 0)
        {
            tank::Game::popState();
        }
    }

    turnTimer_.start();
}

void MainState::update()
{
    summoners_[currentPlayer_]->update(turnTimer_.getTicks());
    summoners_[not currentPlayer_]->update(0);

    if (turnTimer_.getTicks() > 1000 * settings::turnTime)
    {
        endTurn();
    }

    if (eventHandler.check("quit"))
    {
        tank::Game::popState();
    }

    tank::State::update();
}

void MainState::resolveAttacks()
{
    Field& playerField = summoners_[0]->getField();
    Field& enemyField = summoners_[1]->getField();

    unsigned int playerDamage = 0;
    unsigned int enemyDamage = 0;

    for (unsigned int i = 0; i < 6; ++i)
    {
        if (playerField.isActive(i) and enemyField.isActive(i))
        {
            if (playerField.isAttacking(i) and enemyField.isAttacking(i))
            {
                playerDamage += enemyField.getCard(i)->getStrength();
                enemyDamage += playerField.getCard(i)->getStrength();
            }
            else if (playerField.isAttacking(i))
            {
                int damage = playerField.getCard(i)->getStrength() -
                             enemyField.getCard(i)->getStrength();
                if(damage > 0)
                {
                    playerDamage += damage;
                }
                else if (damage < 0)
                {
                    enemyDamage -= damage;
                }
            }
            else if (enemyField.isAttacking(i))
            {
                int damage = playerField.getCard(i)->getStrength() -
                             enemyField.getCard(i)->getStrength();
                if(damage > 0)
                {
                    enemyDamage += damage;
                }
                else if (damage < 0)
                {
                    playerDamage -= damage;
                }
            }
        }
        else if (playerField.isActive(i))
        {
            if (playerField.isAttacking(i))
            {
                enemyDamage += playerField.getCard(i)->getStrength();
            }
        }
        else if (enemyField.isActive(i))
        {
            if (enemyField.isAttacking(i))
            {
                playerDamage += enemyField.getCard(i)->getStrength();
            }
        }
    }

    summoners_[0]->damage(playerDamage);
    summoners_[1]->damage(enemyDamage);

    std::cout << summoners_[0]->name << " takes " << playerDamage << " damage "
              << "and  is on " << summoners_[0]->getLife() << " health" << std::endl;
    std::cout << summoners_[1]->name << " takes " << enemyDamage << " damage "
              << "and  is on " << summoners_[1]->getLife() << " health" << std::endl;
}
