#include "Card.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <Tank/System/Game.hpp>
#include "Resources.hpp"
#include "Deck.hpp"

const double Card::rarityToChance[4] {
    std::exp(3), std::exp(2), std::exp(1), std::exp(0)
};

Card::Card(std::string xmlPath, std::string imagePath, Deck const& deck)
    : deck(deck)
{
    tank::Game::log << "Attempting to load card " << xmlPath
                    << " with image " << imagePath << std::endl;

    boost::property_tree::ptree cardTree;
    boost::property_tree::read_xml(xmlPath, cardTree);

    name_ = cardTree.get("name","unnamed");
    strength_ = cardTree.get<unsigned int>("strength");
    cost_ = cardTree.get<unsigned int>("cost");
    rarity_ = cardTree.get<unsigned int>("rarity");
    relativeChance_ = rarityToChance[rarity_];
    ability_ = static_cast<Ability>(cardTree.get("ability",0));

    imagePath = cardTree.get("image",imagePath);
    image_.load(imagePath);
}

CardGUI::CardGUI(tank::Vectorf pos, Card const* card)
    : ZoomHack(pos)
{
    makeGraphic<tank::Image>(card->deck.backing);
    makeGraphic<tank::Image>(card->deck.rarity[card->getRarity()]);

    for (unsigned int i = 0; i < card->getStrength(); ++i)
    {
        makeGraphic<tank::Image>(res::powerIcon)->setOrigin({- 36.f, - 16.f - i * 9.f});
    }

    for (unsigned int i = 0; i < card->getCost(); ++i)
    {
        makeGraphic<tank::Image>(res::costIcon)->setOrigin({- 3.f, - 16.f - i * 9.f});
    }

    makeGraphic<tank::Image>(card->getImage());
}
