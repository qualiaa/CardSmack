#include "Deck.hpp"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <numeric>
#include <cstdlib>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

const double Card::rarityToChance[4] {
    std::exp(3), std::exp(2), std::exp(1), std::exp(0)
};

Deck::Deck(std::string filePath)
    : relChanceTotal_(0)
{
    std::string xmlFolder = filePath + "/xml";
    std::string imageFolder = filePath + "/gfx";

    std::cout << "Loading deck " << filePath << std::endl;

    for (boost::filesystem::directory_iterator fileIter(xmlFolder);
         fileIter != boost::filesystem::directory_iterator();
         ++fileIter)
    {
        std::cout << fileIter->path().extension() << std::endl;
        if (fileIter->path().extension() == ".xml")
        {
            auto path = fileIter->path();
            cards_.push_back(
                Card(path.string(),
                     imageFolder + "/" + path.stem().string() + ".png"));
        }
    }

    for (auto card : cards_)
    {
        relChanceTotal_ += card.getRelativeChance();
    }
}

Card const* Deck::drawCard() const
{
    unsigned int chanceRoll = std::rand() % relChanceTotal_;
    unsigned int chanceSum = 0;
    Card const* selection = nullptr;

    for (auto& card : cards_)
    {
        chanceSum += card.getRelativeChance();
        selection = &card;

        if (chanceSum > chanceRoll)
        {
            break;
        }
    }

    if (not selection)
    {
        throw std::runtime_error("Error selecting card");
    }

    return selection;
}

Card::Card(std::string xmlPath, std::string imagePath)
{
    std::cout << "Attempting to load card " << xmlPath
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

    std::cout << "Name: " << name_ << std::endl;
    std::cout << "Strength: " << strength_ << std::endl;
    std::cout << "Cost: " << cost_ << std::endl;
    std::cout << "Relative Chance: " << relativeChance_ << std::endl;
    std::cout << "Image: " << imagePath << std::endl;
}
