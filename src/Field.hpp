#ifndef FIELD_HPP
#define FIELD_HPP

#include <array>
#include <Tank/System/Entity.hpp>
#include <Tank/Utility/Timer.hpp>
#include "Deck.hpp"
#include "InactiveSlot.hpp"

class Field
{
public:
    struct Slot
    {
        Card const* card {nullptr};
        bool attacking {false};
        tank::Timer timer{};
    };

    Field();

    void update();
    unsigned int getTimeRemaining(unsigned int slot) const;

    void removeCard(unsigned int slot);
    void setCard(Card const*, unsigned int slot);
    Card const* getCard(unsigned int slot) const;

    bool isActive(unsigned int slot) const;
    void toggleAttack(unsigned int slot);
    bool isAttacking(unsigned int slot) const;
private:
    std::array<Slot, 6> slots_;
};

class FieldGUI : public tank::Entity
{
public:
    FieldGUI(tank::Vectorf pos, Field const&);
    virtual void update() override;
    virtual void draw(tank::Vectorf cam) override;
private:
    Field const& field_;

    std::array<CardSlot, 6> cardSlots_;
};

#endif /* FIELD_HPP */
