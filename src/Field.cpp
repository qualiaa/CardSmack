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

unsigned int Field::getTimeRemaining(unsigned int slot) const
{
    if(slots_[slot].card)
    {
        return slots_[slot].timer.getTicks();
    }

    return 0;
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
}

Card const* Field::getCard(unsigned int slot) const
{
    return slots_[slot].card;
}

bool Field::isActive(unsigned int slot) const
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
    return slots_[slotIndex].attacking;
}

FieldGUI::FieldGUI(tank::Vectorf pos, Field const& field)
    : Entity(pos)
    , field_(field)
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        cardSlots_[i].setPos({getPos().x + settings::cardSpace * i,
                              getPos().y});
    }
}

void FieldGUI::update()
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        if (cardSlots_[i].getCard() != field_.getCard(i))
        {
            cardSlots_[i].setCard(field_.getCard(i));
        }
    }
}

void FieldGUI::draw(tank::Vectorf cam)
{
    for (unsigned int i = 0; i < 6; ++i)
    {
        cardSlots_[i].draw(cam);

        if (field_.isActive(i))
        {
            tank::Vectorf pos = getPos() + tank::Vectorf{
                        static_cast<float>(settings::cardSpace * i), 0.f};

            float ratio = static_cast<float>(field_.getTimeRemaining(i)) /
                          static_cast<float>(settings::cardTime * 1000);

            std::cout << ratio << std::endl;

            InvalidSlot slot(pos, false);
            slot.setRatio(ratio);
            slot.draw(cam);
        }
    }
}
