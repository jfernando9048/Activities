#pragma once
#include "Player.h"
#include <vector>
#include <stack>

class Game {
private:
    int numPlayers;
    std::vector<Player> players;
    mutable std::stack<Card> deck;
    std::stack<Card> discarded;

public:
    Game(int numPlayers);

    Card GetNewCard() const;
    void DiscardCard(const Card card);
    void PrintDiscarded() const;

    //Extra method to test that everything works
    void PrintPlayers() const;
};