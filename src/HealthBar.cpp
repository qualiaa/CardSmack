#include "HealthBar.hpp"

#include "Resources.hpp"
#include "Settings.hpp"


const unsigned int HealthBar::maxWidth = 446;

HealthBar::HealthBar(Summoner const* summoner, bool player)
    : Entity(tank::Vectorf{0.f, 0.f})
    , summoner_(summoner)
{
    bar_ = makeGraphic<tank::Image>(res::health);
    bar_->setPos({17.f,7.f});

    if (player)
    {
        setPos({239, 608});
        makeGraphic<tank::Image>(res::playerHealth);
    }
    else
    {
        setPos({241, 31});
        makeGraphic<tank::Image>(res::enemyHealth);
    }
}

void HealthBar::update()
{
    float ratio = static_cast<float>(summoner_->getLife()) / 
                  static_cast<float>(settings::maxLife);

    setRatio(ratio);
}

void HealthBar::setRatio(float ratio)
{
    bar_->setSize({ratio * maxWidth, static_cast<float>(bar_->getTextureSize().y)});
}
