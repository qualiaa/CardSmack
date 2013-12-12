#include "Player.hpp"

#include <Tank/System/Keyboard.hpp>
#include "MainState.hpp"

Player::Player(std::unique_ptr<Deck> const& deck, MainState& game)
    : Summoner(deck, game)
{
    using kbd = tank::Keyboard;
    using key = tank::Key;

    // TODO: Support Dvorak
    game_.connect(kbd::KeyPress(key::A), [this]{shiftHandLeft();});
    game_.connect(kbd::KeyPress(key::S), [this]{makeAction(0);});
    game_.connect(kbd::KeyPress(key::D), [this]{makeAction(1);});
    game_.connect(kbd::KeyPress(key::F), [this]{makeAction(2);});
    game_.connect(kbd::KeyPress(key::J), [this]{makeAction(3);});
    game_.connect(kbd::KeyPress(key::K), [this]{makeAction(4);});
    game_.connect(kbd::KeyPress(key::L), [this]{makeAction(5);});
    game_.connect(kbd::KeyPress(key::SemiColon), [this]{shiftHandRight();});
    game_.connect(kbd::KeyPress(key::Space) or kbd::KeyPress(key::Return),
                          [this]{endTurn();});
}

void Player::makeAction(unsigned int slot)
{
    if (time_ > 0)
    {
        if (field_.isActive(slot))
        {
            toggleAttack(slot);
        }
        else
        {
            play(slot);
            toggleAttack(slot);
        }
    }
}
