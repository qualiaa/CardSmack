#ifndef MENUSTATE_HPP
#define MENUSTATE_HPP

#include <Tank/System/World.hpp>
#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/FrameList.hpp>

class MenuItems : public tank::Entity
{
    static const std::string buttons[4];
    int index_;
    tank::observing_ptr<tank::FrameList> menuItems_;

public:
    MenuItems();
    virtual void onAdded() override;

private:
    void left();
    void right();
    void select();
};

class MenuState : public tank::World
{
public:
    MenuState();
private:
};

#endif /* MENUSTATE_HPP */
