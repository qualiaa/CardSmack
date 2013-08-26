#include "Card.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <Tank/System/Game.hpp>

const double Card::rarityToChance[4] {
    std::exp(3), std::exp(2), std::exp(1), std::exp(0)
};

Card::Card(std::string xmlPath, std::string imagePath)
{
    tank::Game::log << "Attempting to load card " << xmlPath
                    << " with image " << imagePath << std::endl;

    boost::property_tree::ptree cardTree;
    boost::property_tree::read_xml(xmlPath, cardTree);

    name_ = cardTree.get("name","unnamed");
    strength_ = cardTree.get<unsigned int>("strength");
    cost_ = cardTree.get<unsigned int>("cost");
    relativeChance_ = rarityToChance[cardTree.get<unsigned int>("rarity")];
    ability_ = static_cast<Ability>(cardTree.get("ability",0));

    imagePath = cardTree.get("image",imagePath);
    image_.load(imagePath);
}
