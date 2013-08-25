#include "Field.hpp"

#include <iostream>
#include "Settings.hpp"

Field::Field() { }

void Field::update()
{
    for (unsigned int i = 0; i < slots_.size(); ++i)
    {
        if (slots_[i].card)
        {
            if (slots_[i].timer.getTicks() > 1000 * settings::turnTime)
            {
                removeCard(i);
            }
        }
    }
}

void Field::removeCard(unsigned int slot)
{
    std::cout << "[Slot " << slot << "] "
              << slots_[slot].card->getName() << " dies" << std::endl;

    slots_[slot].card = nullptr;
    slots_[slot].timer.stop();
}

void Field::setCard(Card const* card, unsigned int slot)
{
    slots_[slot].card = card;
    slots_[slot].timer.start();
    slots_[slot].attacking = false;

    std::cout << "[Slot " << slot << "] "
              << "Played " << card->getName() << std::endl;
}

Card const* Field::getCard(unsigned int slot) const
{
    return slots_[slot].card;
}

bool Field::isTaken(unsigned int slot) const
{
    return slots_[slot].card;
}

void Field::toggleAttack(unsigned int slotIndex)
{
    Slot& slot = slots_[slotIndex];

    slot.attacking = not slot.attacking;

    std::cout << "[Slot " << slotIndex << "] "
              << "Set to ";
    if(slot.attacking)
    {
        std::cout << "attack" << std::endl;
    }
    else
    {
        std::cout << "defend" << std::endl;
    }
}

bool Field::isAttacking(unsigned int slotIndex) const
{
    /*Slot const& slot = slots_[slotIndex];

    if (slot.card)
    {
    */
        return slots_[slotIndex].attacking;
    /*
    }

    return false;
    */
}
