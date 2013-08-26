#ifndef INACTIVESLOT_HPP
#define INACTIVESLOT_HPP

#include <Tank/Graphics/Image.hpp>
#include "ZoomHack.hpp"

class InvalidSlot : public ZoomHack
{
public:
    InvalidSlot(tank::Vectorf pos, bool full);
    void setRatio(float);
private:
    tank::Vectoru dimensions_;
    tank::observing_ptr<tank::Image> image_;

};

#endif
