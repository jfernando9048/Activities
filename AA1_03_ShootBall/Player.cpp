#include "Player.h"

//We initializes the player
void Player::init(std::string name, int position) {
    this->name = name;
    this->position = position;
    this->score = 0; //Initializes the score to 0
    this->gunSize = 30; //Loads the gun, now with 30 balls

    this->gun = new Ball[this->gunSize];
    for (int i = 0; i < this->gunSize; i++) {
        this->gun[i] = getRandomBall(); //To randomize the balls
    }
}

//Shoots the first ball and removes it from the magazine
Ball Player::shoot() {
    Ball shot = gun[0]; //Extract the first ball

    Ball* newGun = nullptr;
    if (gunSize - 1 > 0) {
        newGun = new Ball[gunSize - 1];
        //Copy all balls shifting them to the left
        for (int i = 0; i < gunSize - 1; i++) {
            newGun[i] = gun[i + 1];
        }
    }

    delete[] gun; //Free the memory of the old magazine
    gun = newGun; //Assign the new magazine
    gunSize--;

    return shot; //The function returns it
}

Player::~Player() {
    if (gun != nullptr) {
        delete[] gun;
    }
}