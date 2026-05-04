#define BALL_H
#define BALL_H

//Balls can be of 5 different colors
enum class Color { RED, GREEN, BLUE, YELLOW, PURPLE };

//Define the Ball type
struct Ball {
    Color color;
};

//Auxiliary functions
Ball getRandomBall();
void printBall(const Ball& b);