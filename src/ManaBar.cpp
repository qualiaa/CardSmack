#include "ManaBar.hpp"

#include <iostream>

#include "Resources.hpp"
#include "Settings.hpp"


const unsigned int ManaBar::maxWidth = 446;

ManaBar::ManaBar(Summoner const* summoner)
    : Entity(tank::Vectorf{239.f, 638.f})
    , summoner_(summoner)
{
    bar_ = makeGraphic<tank::Image>(res::mana);
    bar_->setPos({17.f,7.f});

    makeGraphic<tank::Image>(res::playerMana);
}

void ManaBar::update()
{
    float mana = summoner_->getMana();
    mana += static_cast<float>(summoner_->getManaTicks() / 2500.f);
    float ratio = mana / static_cast<float>(settings::maxMana);

    setRatio(ratio);
}

void ManaBar::setRatio(float ratio)
{
    bar_->setSize({ratio * maxWidth, static_cast<float>(bar_->getTextureSize().y)});
}
