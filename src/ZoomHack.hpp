#ifndef ZOOMHACK_HPP
#define ZOOMHACK_HPP

#include "Tank/System/Entity.hpp"
#include "Tank/Utility/Vector.hpp"

class ZoomHack : public tank::Entity
{
public:
    ZoomHack(tank::Vectorf pos);
    virtual void draw(tank::Vectorf camera) override;

    static unsigned int getScale()
    {
        return scale_;
    }

    static void setScale(unsigned int scale)
    {
        scale_ = scale;
    }
private:
    static unsigned int scale_;
};

#endif /* ZOOMHACK_HPP */
