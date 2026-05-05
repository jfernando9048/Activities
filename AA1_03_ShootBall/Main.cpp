#include <iostream>
#include <ctime>
#include "Player.h"
#include "Panel.h"

//MAIN
 
//Implement a main with the game loop
int main() {
    srand(static_cast<unsigned int>(time(nullptr))); //Random seed initialization

    std::cout << "--- Welcome to Zumita ---\n";

    Panel panel;
    panel.init();

    Player player;
    //Initializes the player, setting name and position 0
    player.init("Player 1", 0);

    //The game ends when the magazine is empty
    while (player.gunSize > 0) {
        std::cout << "\n===================================\n";
        std::cout << "Actual panel (" << panel.size << " balls): ";
        panel.printPanel();

        std::cout << "Player: " << player.name << " | Score: " << player.score << "\n";
        std::cout << "Balls in magazine: " << player.gunSize << " | Next ball to shoot: ";
        printBall(player.gun[0]); //Always shoots the first ball
        std::cout << "\n";

        //Decide how the inputs should be to play
        int targetPos;
        std::cout << "Position where it will impact (0 to " << panel.size << "): ";
        std::cin >> targetPos;

        if (targetPos < 0) targetPos = 0;
        if (targetPos > panel.size) targetPos = panel.size;

        //The player shoots
        player.position = targetPos;
        Ball shotBall = player.shoot();

        //Impacts the panel and inserts
        panel.insert(targetPos, shotBall);

        //If 3 balls are achieved, earns 1 point, 3 disappear, 3 new ones are generated
        int comboPos = panel.verifier(targetPos, shotBall);
        if (comboPos != -1) {
            std::cout << "¡COMBO! +1 Point. Removing 3 balls and adding 3 at the end...\n";
            player.score++;
            panel.deleteThree(comboPos);
            panel.insertThree();
        }

        if (panel.size == 0) {
            std::cout << "\nYou've destroyed the entire panel!\n";
            break;
        }
    }

    std::cout << "\n--- END OF THE GAME ---\n";
    std::cout << "Empty magazine.\n";
    std::cout << "Final Score: " << player.score << "\n";

    return 0;
}