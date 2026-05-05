#pragma once
#include "Types.h"

class Card {
public:
    Suit suit;
    int value;

    // Constructor
    Card(Suit suit, int value);

    // Operator ==
    bool operator==(const Card& other) const;

    //Extra useful operators for comparing and sorting
    bool operator>(const Card& other) const;
    bool operator<(const Card& other) const;
};