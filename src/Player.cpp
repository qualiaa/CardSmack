#include "Player.hpp"

#include <iostream>
#include <Tank/System/EventHandler.hpp>
#include "MainState.hpp"

Player::Player(Deck const* deck, MainState& game)
    : Summoner(deck, game)
{
    // TODO: Support Dvorak
    game_.eventHandler.define("shiftLeft", { tank::Key::A });
    game_.eventHandler.define("playSlot0", { tank::Key::S });
    game_.eventHandler.define("playSlot1", { tank::Key::D });
    game_.eventHandler.define("playSlot2", { tank::Key::F });
    game_.eventHandler.define("playSlot3", { tank::Key::J });
    game_.eventHandler.define("playSlot4", { tank::Key::K });
    game_.eventHandler.define("playSlot5", { tank::Key::L });
    game_.eventHandler.define("shiftRight", { tank::Key::SemiColon });
    game_.eventHandler.define("endTurn", { tank::Key::Space });
}

void Player::gameLogic(unsigned int turnTime)
{
    if (game_.eventHandler.check("shiftLeft"))
    {
        shiftHandLeft();
    }
    else if (game_.eventHandler.check("shiftRight"))
    {
        shiftHandRight();
    }

    if (turnTime)
    {
        if (game_.eventHandler.check("playSlot0"))
        {
            makeAction(0);
        }
        if (game_.eventHandler.check("playSlot1"))
        {
            makeAction(1);
        }
        if (game_.eventHandler.check("playSlot2"))
        {
            makeAction(2);
        }
        if (game_.eventHandler.check("playSlot3"))
        {
            makeAction(3);
        }
        if (game_.eventHandler.check("playSlot4"))
        {
            makeAction(4);
        }
        if (game_.eventHandler.check("playSlot5"))
        {
            makeAction(5);
        }
        if (game_.eventHandler.check("endTurn"))
        {
            game_.endTurn();
        }
    }
}

void Player::makeAction(unsigned int slot)
{
    if (field_.isActive(slot))
    {
        field_.toggleAttack(slot);
    }
    else
    {
        play(slot);
    }
}
