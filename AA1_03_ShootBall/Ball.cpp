#include "Ball.h"
#include <cstdlib>
#include <iostream>

Ball getRandomBall() {
    //Returns a ball with a random color between 0 and 4
    return { static_cast<Color>(rand() % 5) };
}

void printBall(const Ball& b) {
    char c;
    switch (b.color) {
    case Color::RED: c = 'R'; break;
    case Color::GREEN: c = 'G'; break;
    case Color::BLUE: c = 'B'; break;
    case Color::YELLOW: c = 'Y'; break;
    case Color::PURPLE: c = 'P'; break;
    }
    //Add a small visual format using color initials
    std::cout << "[" << c << "]";
}