#include "CardOverlay.hpp"

#include "Resources.hpp"

CardOverlay::CardOverlay(tank::Vectorf pos)
    : ZoomHack(pos)
{
    image_ = makeGraphic<tank::Image>(res::cardInactive);
    dimensions_ = image_->getTextureSize();
}

void CardOverlay::setRatio(float ratio)
{
    unsigned int visible = dimensions_.y - std::round(ratio  * dimensions_.y);

    image_->setPos( {0.f, static_cast<float>(visible) * ZoomHack::getScale()} );
    image_->setClip({0, visible, dimensions_.x, dimensions_.y});
}
