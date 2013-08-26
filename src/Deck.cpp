#include "Deck.hpp"

#include <stdexcept>
#include <exception>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <boost/filesystem.hpp>
#include <Tank/System/Game.hpp>

Deck::Deck(std::string filePath)
    : relChanceTotal_(0)
{
    std::string xmlFolder = filePath + "/xml/";
    std::string imageFolder = filePath + "/gfx/";

    tank::Game::log << "Loading deck " << filePath << std::endl;

    for (boost::filesystem::directory_iterator fileIter(xmlFolder);
         fileIter != boost::filesystem::directory_iterator();
         ++fileIter)
    {
        if (fileIter->path().extension() == ".xml")
        {
            auto path = fileIter->path();
            cards_.push_back(
                Card(path.string(),
                     imageFolder + path.stem().string() + ".png",
                     this));
        }
    }

    rarity[0].load(imageFolder + "Common.png");
    rarity[1].load(imageFolder + "Uncommon.png");
    rarity[2].load(imageFolder + "Rare.png");
    rarity[3].load(imageFolder + "Mythic.png");
    backing.load(imageFolder + "Backing.png");

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
