#pragma once
#include <cstdint>

enum class Side {BID, ASK};
enum class Type {LIMIT, MARKET};

struct Order{
    uint64_t id;
    Side side;
    Type type;
    double price;
    uint32_t quantity;
    uint64_t timestamp;
};


