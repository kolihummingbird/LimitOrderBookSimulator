#pragma once
#include "Order.hpp"
#include <map>
#include <queue>
#include <unordered_map>
#include <functional>
#include <iostream>
#include <vector>

class OrderBook
{
private:
    std::map<double, std::vector<Order>, std::greater<>> bids;
    std::map<double, std::vector<Order>> asks;   
    std::unordered_map<uint64_t, Order> lookup;
public:

    void addLimitOrder(Order order)
    {
        if (order.side == Side::BID) bids[order.price].push_back(order);
        else asks[order.price].push_back(order);
        lookup[order.id] = order;
    }

    void printBook(int depth)
    {
        int counter = 0; // counting depth
        std::cout<< "-- BIDS -- \n";
        for (auto& [price, orders] : bids)
        {
            if (depth == counter) break;
            uint32_t total = 0;
            for (auto& o : orders) total += o.quantity;
            counter++;
            std::cout << price << " " << total << std::endl;
        }

        counter = 0;
        std::cout<< "-- ASKS -- \n";
        for (auto& [price, orders] : asks)
        {
            if (depth == counter) break;
            uint32_t total = 0;
            for (auto& o : orders) total += o.quantity;
            counter++;
            std::cout << price << " " << total << std::endl;
        }
    }
};
