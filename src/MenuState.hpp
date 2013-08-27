#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <Tank/System/State.hpp>
#include <Tank/Graphics/Animation.hpp>
#include "Resources.hpp"

class MenuItems : public tank::Entity
{
public:
    MenuItems();

    virtual void update() override;
private:
    static const std::string buttons[4];
    int index_;
    tank::observing_ptr<tank::Animation> menuItems_;
};

class MenuState : public tank::State
{
public:
    MenuState();

    virtual void update() override;
private:
};

#endif /* MENUSTATE_HPP */
