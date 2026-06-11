#include<iostream>
#include "Order.hpp"

int main()
{
    Order OrderOne = {1,Side::BID,Type::LIMIT, 105.75, 10, 1000};
    Order OrderTwo{2,Side::ASK,Type::MARKET, 104.25, 5, 4550};
    std::cout<< OrderOne.id << " " << static_cast<int>(OrderOne.side) <<" " << static_cast<int>(OrderOne.type) 
    << " " << OrderOne.price << " " << OrderOne.quantity << " " << OrderOne.timestamp << std::endl;

    std::cout<< OrderTwo.id << " " << static_cast<int>(OrderTwo.side) <<" " << static_cast<int>(OrderTwo.type)
    << " " << OrderTwo.price << " " << OrderTwo.quantity << " " << OrderTwo.timestamp << std::endl;
    


}
