#ifndef CARDOVERLAY_HPP
#define CARDOVERLAY_HPP

#include <Tank/Graphics/Image.hpp>
#include "ZoomHack.hpp"

class CardOverlay : public ZoomHack
{
public:
    CardOverlay(tank::Vectorf pos);
    void setRatio(float);
private:
    tank::Vectoru dimensions_;
    tank::observing_ptr<tank::Image> image_;

};

#endif /* CARDOVERLAY_HPP */
