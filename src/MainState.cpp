#include "MainState.hpp"

#include <boost/filesystem.hpp>
#include <Tank/System/Game.hpp>
#include <Tank/System/Keyboard.hpp>
#include "Resources.hpp"
#include "Settings.hpp"
#include "Player.hpp"
#include "AI.hpp"
#include "HealthBar.hpp"
#include "ManaBar.hpp"
#include "TimeBar.hpp"

MainState::MainState()
    : currentPlayer_(0)
{
    using kbd = tank::Keyboard;
    using key = tank::Key;
    //Load the Decks from res/decks
    for (boost::filesystem::directory_iterator deckIter("res/decks");
         deckIter != boost::filesystem::directory_iterator();
         ++deckIter)
    {
        decks_.emplace_back(new Deck(deckIter->path().string()));
    }

    //Create the players
    summoners_[0].reset(new Player(decks_.back(), *this));
    summoners_[1].reset(new AI(decks_.front(), *this));

    summoners_[0]->name = "Player";
    summoners_[1]->name = "AI";

    //Set up the GUI
    makeEntity<tank::Entity>(tank::Vectorf{})->
        makeGraphic<tank::Image>(res::playingField);
    makeEntity<HandGUI>(tank::Vectorf {56.f, 216.f }, summoners_[0]);
    makeEntity<FieldGUI>(tank::Vectorf {56.f, 128.f},
                         summoners_[0]->getField(),
                         true);
    makeEntity<FieldGUI>(tank::Vectorf {56.f, 48.f},
                         summoners_[1]->getField(),
                         false);

    makeEntity<HealthBar>(summoners_[1], false);
    makeEntity<HealthBar>(summoners_[0], true);
    makeEntity<TimeBar>(summoners_[0]);
    makeEntity<ManaBar>(summoners_[0]);

    connect(kbd::KeyRelease(key::Escape), []{ tank::Game::popWorld(); });

    turnTimer_.start();
}


void MainState::endTurn()
{
    resolveAttacks();
    currentPlayer_ = not currentPlayer_;

    for (auto& p : summoners_)
    {
        if (p->getLife() == 0)
        {
            tank::Game::popWorld();
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

    tank::World::update();
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
}
