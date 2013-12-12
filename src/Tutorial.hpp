#ifndef TUTORIAL_HPP
#define TUTORIAL_HPP

#include <Tank/System/World.hpp>

class Tutorial : public tank::World
{
public:
    Tutorial();

private:
    tank::observing_ptr<tank::Entity> tut1_;
    tank::observing_ptr<tank::Entity> tut2_;

    void nextPage();
    void previousPage();

    bool finished_;
};

#endif /* TUTORIAL_HPP */
