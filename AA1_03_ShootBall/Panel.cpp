#include "Panel.h"
#include <iostream>

//Destructor
Panel::~Panel() {
    if (panel != nullptr) delete[] panel;
}

//Modifies the number of balls that can be in the panel
void Panel::resizePanel(int newSize) {
    if (newSize <= 0) {
        delete[] panel;
        panel = nullptr;
        size = 0;
        return;
    }

    Ball* newPanel = new Ball[newSize];
    int limit = (size < newSize) ? size : newSize;
    for (int i = 0; i < limit; i++) {
        newPanel[i] = panel[i];
    }

    delete[] panel;
    panel = newPanel;
    size = newSize;
}

//Initializes the panel with a number read from standard input
void Panel::init() {
    int initialSize;
    std::cout << "Enter the initial number of balls for the panel: ";
    std::cin >> initialSize; //Read from standard input

    size = 0;
    panel = nullptr;
    resizePanel(initialSize);

    //Initialize without having more than 2 consecutive identical balls
    for (int i = 0; i < size; i++) {
        bool valid = false;
        Ball b;
        while (!valid) {
            b = getRandomBall();
            //Check that it doesn't match the 2 previous ones
            if (i >= 2 && panel[i - 1].color == b.color && panel[i - 2].color == b.color) {
                valid = false;
            }
            else {
                valid = true;
            }
        }
        panel[i] = b;
    }
}

//Prints the balls into the panel
void Panel::printPanel() const {
    for (int i = 0; i < size; i++) {
        printBall(panel[i]);
    }
    std::cout << std::endl;
}
//Inserts the ball at the position, shifting to the right
void Panel::insert(int position, Ball ball) {
    if (position < 0) position = 0;
    if (position > size) position = size;

    int oldSize = size;
    resizePanel(oldSize + 1); //The panel grows

    //Shift to the right
    for (int i = oldSize; i > position; i--) {
        panel[i] = panel[i - 1];
    }
    panel[position] = ball; //Insert at the impact location
}

//Verifies if there are 3 consecutive, returns starting position or -1
int Panel::verifier(int position, Ball ball) const {
    int count = 1;
    int left = position - 1;
    int right = position + 1;

    //Count to the left
    while (left >= 0 && panel[left].color == ball.color) {
        count++;
        left--;
    }
    //Count to the right
    while (right < size && panel[right].color == ball.color) {
        count++;
        right++;
    }

    if (count >= 3) {
        return left + 1; //Returns where the first of the 3 balls is located
    }
    return -1; //Indicate in some way if there aren't 3
}

//Deletes 3 balls starting from the position
void Panel::deleteThree(int position) {
    if (position < 0 || position + 2 >= size) return;

    //Shift left to overwrite the 3 deleted ones
    for (int i = position; i < size - 3; i++) {
        panel[i] = panel[i + 3];
    }
    resizePanel(size - 3); //The panel shrinks
}

//Inserts 3 random balls at the end
void Panel::insertThree() {
    int oldSize = size;
    resizePanel(size + 3);
    for (int i = oldSize; i < size; i++) {
        panel[i] = getRandomBall();
    }
}