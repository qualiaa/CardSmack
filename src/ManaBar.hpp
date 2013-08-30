#ifndef MANABAR_HPP
#define MANABAR_HPP

#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/Image.hpp>
#include "Summoner.hpp"

class ManaBar : public tank::Entity
{
public:
    ManaBar(std::unique_ptr<Summoner> const& summoner);

    virtual void update() override;
private:
    std::unique_ptr<Summoner> const& summoner_;
    tank::observing_ptr<tank::Image> bar_;

    void setRatio(float ratio);
    static const unsigned int maxWidth;
};

#endif /* MANABAR_HPP */
