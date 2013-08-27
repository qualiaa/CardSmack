#include "MenuState.hpp"

#include <Tank/System/Game.hpp>
#include "MainState.hpp"

const std::string MenuItems::buttons[4] = {
    "play", "tutorial", "credits", "quit"
};

MenuItems::MenuItems()
    : tank::Entity(tank::Vectorf{224.f,440.f})
{
    index_ = 0;
    menuItems_ = makeGraphic<tank::Animation>(res::menuItems,
                                              tank::Vectoru {547, 58});

    menuItems_->add(buttons[0], {0}, 0);
    menuItems_->add(buttons[1], {1}, 0);
    menuItems_->add(buttons[2], {2}, 0);
    menuItems_->add(buttons[3], {3}, 0);
    menuItems_->select(buttons[0]);
}

void MenuItems::update()
{
    if (getState()->eventHandler.check("left"))
    {
        if (--index_ < 0)
        {
            index_ = 3;
        }

        menuItems_->select(buttons[index_]);
    }
    else if (getState()->eventHandler.check("right"))
    {
        if (++index_ > 3)
        {
            index_ = 0;
        }

        menuItems_->select(buttons[index_]);
    }
    else if (getState()->eventHandler.check("select"))
    {
        switch (index_)
        {
        case 0:
            tank::Game::makeState<MainState>();
            break;
        case 1:
            //tank::pushState<
            break;
        case 2:
            //tank::pushState<
            break;
        case 3:
            tank::Game::stop();
            break;
        default:
            break;
        }
    }
}

MenuState::MenuState()
{
    makeEntity<tank::Entity>(tank::Vectorf{})->makeGraphic<tank::Image>(res::menuScreen);
    makeEntity<MenuItems>();

    eventHandler.define("left", { tank::Key::A, tank::Key::Left });
    eventHandler.define("right", { tank::Key::SemiColon, tank::Key::Right, tank::Key::D });
    eventHandler.define("select", { tank::Key::Return, tank::Key::Space });
    eventHandler.define("quit", { tank::Key::Escape });
}

void MenuState::update()
{
    tank::State::update();
}
