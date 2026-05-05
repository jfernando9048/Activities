#pragma once

#include <string>
#include "Ball.h"

//Implement the Player struct
struct Player {
    std::string name="";
    int position =0;
    int score=0;

    //Gun representation (ball magazine) using dynamic memory
    Ball* gun=nullptr;
    int gunSize=0;

    //Required methods
    void init(std::string name, int position);
    Ball shoot();

    //Destructor to prevent memory leaks
    ~Player();
};