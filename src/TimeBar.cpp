#include "TimeBar.hpp"

#include "Resources.hpp"
#include "Settings.hpp"


const unsigned int TimeBar::maxWidth = 446;

TimeBar::TimeBar(Summoner const* summoner)
    : Entity(tank::Vectorf{239.f, 625.f})
    , summoner_(summoner)
{
    bar_ = makeGraphic<tank::Image>(res::time);
    bar_->setPos({17.f,7.f});
    makeGraphic<tank::Image>(res::playerTime);
}

void TimeBar::update()
{
    float ratio = 0;
    if (summoner_->getTime() != 0)
    { 
        ratio = 1 -  static_cast<float>(summoner_->getTime()) /
                static_cast<float>(settings::turnTime * 1000);
    }

    setRatio(ratio);
}

void TimeBar::setRatio(float ratio)
{
    bar_->setSize({ratio * maxWidth, static_cast<float>(bar_->getTextureSize().y)});
}
