#ifndef TUTORIAL_HPP
#define TUTORIAL_HPP

#include <Tank/System/State.hpp>

class Tutorial : public tank::State
{
public:
    Tutorial();

    virtual void update() override;
private:
    tank::observing_ptr<tank::Entity> tut1_;
    tank::observing_ptr<tank::Entity> tut2_;

    bool finished_;
};

#endif /* TUTORIAL_HPP */
