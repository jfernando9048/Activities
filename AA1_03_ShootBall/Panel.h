#define PANEL_H
#define PANEL_H

#include "Ball.h"

//Implement the Panel struct
struct Panel {
    Ball* panel;
    int size;    //Represents the panel size at all times

    void init();
    void insert(int position, Ball ball);
    int verifier(int position, Ball ball) const;
    void resizePanel(int newSize);
    void deleteThree(int position);
    void insertThree();
    void printPanel() const;

    ~Panel(); //Destructor
};