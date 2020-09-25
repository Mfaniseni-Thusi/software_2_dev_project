#include "Ghost.h"

Ghost::Ghost(const Grid& grid):grid_{grid} {}

float Ghost::getYpos() const{
    return yPos;
}

float Ghost::getXpos() const{
    return xPos;
}

void Ghost::setXpos(float x_pos){
    xPos = x_pos;
}

void Ghost::setYpos(float y_pos){
    yPos = y_pos;
}

Ghost::~Ghost(){}
