#include "Deck.hpp"

#include <iostream>
#include <stdexcept>
#include <exception>
#include <boost/filesystem.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

Deck::Deck(std::string filePath)
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
}

Card* Deck::drawCard() const
{
    return nullptr;
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
    rarity_ = cardTree.get<unsigned int>("rarity");
    ability_ = static_cast<Ability>(cardTree.get("ability",0));

    image_.load(cardTree.get("image",imagePath));
}
