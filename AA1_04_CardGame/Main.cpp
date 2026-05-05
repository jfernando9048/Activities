#include "Game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
    //Initialize the seed for random numbers
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    try {
        std::cout << "--- STARTING THE CARD GAME ---\n\n";

        //We created a game with 3 players
        Game myGame(3);

        //We show the initial hands (they should already be sorted thanks to InsertCard)
        myGame.PrintPlayers();

        //We simulate drawing a card from the deck and discarding it.
        std::cout << "\n--- SIMULATING A SHIFT ---\n";
        Card drawnCard = myGame.GetNewCard();
        std::cout << "A card is drawn from the deck. Suit: " << static_cast<int>(drawnCard.suit)
            << " Value: " << drawnCard.value << "\n";

        myGame.DiscardCard(drawnCard);
        myGame.PrintDiscarded();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}