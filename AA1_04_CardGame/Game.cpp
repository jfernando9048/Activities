#include "Game.h"
#include <algorithm>
#include <random>
#include <chrono>

Game::Game(int numPlayers) {
    if (numPlayers < 2) this->numPlayers = 2;
    else if (numPlayers > 8) this->numPlayers = 8;
    else this->numPlayers = numPlayers;

    //Initialize players with random names
    for (int i = 0; i < this->numPlayers; ++i) {
        players.push_back(Player("Player_" + std::to_string(i + 1)));
    }

    //Initialize deck with 52 cards
    std::vector<Card> allCards;
    for (int s = 1; s <= 4; ++s) {
        for (int v = 1; v <= 13; ++v) {
            allCards.push_back(Card(static_cast<Suit>(s), v));
        }
    }

    //Shuffle randomly
    unsigned seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    std::shuffle(allCards.begin(), allCards.end(), std::default_random_engine(seed));

    for (const Card& c : allCards) {
        deck.push(c);
    }

    //Deal 10 cards to each player, one at a time.
    for (int round = 0; round < 10; ++round) {
        for (Player& p : players) {
            if (!deck.empty()) {
                p.InsertCard(GetNewCard());
            }
        }
    }
}

Card Game::GetNewCard() const {
    if (deck.empty()) throw std::runtime_error("The deck is empty");
    Card topCard = deck.top();
    deck.pop(); // Es posible gracias a que deck es mutable
    return topCard;
}

void Game::DiscardCard(const Card card) {
    discarded.push(card);
}

void Game::PrintDiscarded() const {
    if (!discarded.empty()) {
        Card top = discarded.top();
        std::cout << "Last discarded card - Suit: " << static_cast<int>(top.suit)
            << ", Value: " << top.value << std::endl;
    }
    else {
        std::cout << "There are no discarded cards" << std::endl;
    }
}

void Game::PrintPlayers() const {
    for (const Player& p : players) {
        std::cout << p << std::endl;
    }
}