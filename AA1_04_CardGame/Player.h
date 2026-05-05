#pragma once
#include "Card.h"
#include <string>
#include <list>
#include <iostream>

class Player {
private:
    std::string id;
    std::list<Card> hand; // STL container

public:
    Player(std::string id);

    void InsertCard(Card card);
    Card GetCard() const;
    Card GetCard(const Suit& suit);
    void SortCards();

    // Operator << friend to be able to print
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
};