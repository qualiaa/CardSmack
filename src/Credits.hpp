#ifndef CREDITS_HPP
#define CREDITS_HPP

#include <Tank/System/State.hpp>

class Credits : public tank::State
{
public:
    Credits();

    virtual void update() override;
};

#endif /* CREDITS_HPP */
