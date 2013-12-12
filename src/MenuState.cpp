#include "MenuState.hpp"

#include <Tank/System/Game.hpp>
#include <Tank/System/Keyboard.hpp>
#include "Resources.hpp"
#include "MainState.hpp"
#include "Tutorial.hpp"
#include "Credits.hpp"

const std::string MenuItems::buttons[4] = {
    "play", "tutorial", "credits", "quit"
};

MenuItems::MenuItems()
    : tank::Entity(tank::Vectorf{224.f,440.f})
{
    index_ = 0;
    menuItems_ = makeGraphic<tank::FrameList>(res::menuItems,
                                              tank::Vectoru {547, 58});

    menuItems_->add(buttons[0], {0}, 0);
    menuItems_->add(buttons[1], {1}, 0);
    menuItems_->add(buttons[2], {2}, 0);
    menuItems_->add(buttons[3], {3}, 0);
    menuItems_->select(buttons[0]);
}

void MenuItems::onAdded()
{
    using kbd = tank::Keyboard;
    using key = tank::Key;

    connect(kbd::KeyPress(key::A) or
            kbd::KeyPress(key::Left),
            [this]{left();});

    connect(kbd::KeyPress(key::SemiColon) or
            kbd::KeyPress(key::Right) or
            kbd::KeyPress(key::D),
            [this]{right();});

    connect(kbd::KeyPress(key::Return) or
            kbd::KeyPress(key::Space),
            [this]{select();});

    connect(kbd::KeyPress(key::Escape), []{tank::Game::popWorld();});
}

void MenuItems::left()
{
    if (--index_ < 0)
    {
        index_ = 3;
    }

    menuItems_->select(buttons[index_]);
}

void MenuItems::right()
{
    if (++index_ > 3)
    {
        index_ = 0;
    }

    menuItems_->select(buttons[index_]);
}

void MenuItems::select()
{
    switch (index_)
    {
    case 0:
        tank::Game::makeWorld<MainState>();
        break;
    case 1:
        tank::Game::makeWorld<Tutorial>();
        break;
    case 2:
        tank::Game::makeWorld<Credits>();
        break;
    case 3:
        tank::Game::popWorld();
        break;
    default:
        break;
    }
}

MenuState::MenuState()
{
    makeEntity<tank::Entity>(tank::Vectorf{})->makeGraphic(res::menuScreen);
    makeEntity<MenuItems>();
}
