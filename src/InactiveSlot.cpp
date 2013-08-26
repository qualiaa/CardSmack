#include "InactiveSlot.hpp"

#include "Resources.hpp"

InvalidSlot::InvalidSlot(tank::Vectorf pos, bool full)
    : ZoomHack(pos)
{
    image_ = makeGraphic<tank::Image>(res::cardInactive);
    dimensions_ = image_->getTextureSize();
    setRatio(full);
}

void InvalidSlot::setRatio(float ratio)
{
    unsigned int visible = dimensions_.y - std::round(ratio  * dimensions_.y);

    image_->setPos( {0.f, static_cast<float>(visible) * ZoomHack::getScale()} );
    image_->setClip({0, visible, dimensions_.x, dimensions_.y});
}
