#ifndef HEALTHBAR_HPP
#define HEALTHBAR_HPP

#include <Tank/System/Entity.hpp>
#include <Tank/Graphics/Image.hpp>
#include "Summoner.hpp"

class HealthBar : public tank::Entity
{
public:
    HealthBar(std::unique_ptr<Summoner> const&, bool player);

    virtual void update() override;
private:
    std::unique_ptr<Summoner> const& summoner_;
    tank::observing_ptr<tank::Image> bar_;

    void setRatio(float ratio);
    static const unsigned int maxWidth;
};

#endif /* HEALTHBAR_HPP */
