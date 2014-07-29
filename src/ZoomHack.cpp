#include "ZoomHack.hpp"

unsigned int ZoomHack::scale_ = 2;

ZoomHack::ZoomHack(tank::Vectorf pos)
    : Entity(pos)
{}

void ZoomHack::draw(tank::Camera const& camera)
{
    for (auto& g : getGraphicList())
    {
        g->setScale(scale_);
    }
    tank::Entity::draw(camera);
}
