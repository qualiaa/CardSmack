#include "Deck.hpp"

#include <stdexcept>
#include <exception>
#include <boost/filesystem.hpp>

Deck::Deck(std::string filepath)
{
    for (boost::filesystem::directory_iterator fileIter(filepath);
         fileIter != boost::filesystem::directory_iterator();
         ++fileIter)
    {
        if (not boost::filesystem::is_directory(fileIter->status()))
        {
            //std::istream = *fileIter;
            std::cout << fileIter->path() << std::endl;
        }
    }
}

Card* Deck::drawCard() const
{
    return nullptr;
}
