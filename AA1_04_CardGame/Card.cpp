#include "Card.h"

Card::Card(Suit suit, int value) {
    this->suit = suit;
    this->value = value;
}

bool Card::operator==(const Card& other) const {
    return (this->suit == other.suit && this->value == other.value);
}

//Check if this card is higher than "other"
bool Card::operator>(const Card& other) const {
    if (this->suit != other.suit) {
        return this->suit > other.suit; //HEART > DIAMOND > SPADE > CLUB
    }
    return this->value > other.value; //Within the same suit, higher value
}

bool Card::operator<(const Card& other) const {
    if (this->suit != other.suit) {
        return this->suit < other.suit;
    }
    return this->value < other.value;
}