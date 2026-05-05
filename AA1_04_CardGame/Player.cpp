#include "Player.h"
#include <cstdlib>

Player::Player(std::string id) {
    this->id = id;
}

//Insert the card while maintaining the order without using std::sort
void Player::InsertCard(Card card) {
    auto it = hand.begin();
    //We advance the iterator until we find a card lower than the one we inserted.
    while (it != hand.end() && (*it > card || *it == card)) {
        ++it;
    }
    //We insert the card just before that minor card
    hand.insert(it, card);
}

//Returns a random card
Card Player::GetCard() const {
    if (hand.empty()) throw std::runtime_error("Mano vacia");

    int randomIndex = std::rand() % hand.size();
    auto it = hand.begin();
    std::advance(it, randomIndex);
    return *it;
}

//Returns the highest card of a specific suit.
Card Player::GetCard(const Suit& suit) {
    //Since the cards are already inserted in order
    //the first one we find of this suit will be the highest
    for (const Card& c : hand) {
        if (c.suit == suit) {
            return c;
        }
    }
    throw std::runtime_error("There are no cards of this suit");
}

//Manual sorting in case it gets messed up at any point
void Player::SortCards() {
    if (hand.size() < 2) return;

    bool swapped;
    do {
        swapped = false;
        auto it1 = hand.begin();
        auto it2 = hand.begin();
        std::advance(it2, 1);

        while (it2 != hand.end()) {
            if (*it2 > *it1) {
                std::swap(*it1, *it2);
                swapped = true;
            }
            ++it1;
            ++it2;
        }
    } while (swapped);
}

std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << "Player: " << player.id << "\Cards:\n";
    for (const Card& c : player.hand) {
        os << "  - Suit: " << static_cast<int>(c.suit) << ", Value: " << c.value << "\n";
    }
    return os;
}