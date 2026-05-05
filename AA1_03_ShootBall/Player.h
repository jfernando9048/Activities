#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Ball.h"

//Implement the Player struct
struct Player {
    std::string name;
    int position;
    int score;

    //Gun representation (ball magazine) using dynamic memory
    Ball* gun;
    int gunSize;

    //Required methods
    void init(std::string name, int position);
    Ball shoot();

    //Destructor to prevent memory leaks
    ~Player();
};

#endif