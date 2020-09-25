#include "PacmanPlayer.h"

PacmanPlayer::PacmanPlayer(const Grid& grid) : grid_{grid} {}

Position PacmanPlayer::getPosition() const {
         return position_;
}

void PacmanPlayer::setPosition(Position& pos_){
         position_ = pos_;
}

/*
float PacmanPlayer::getYpos() const{
    return yPos;
}

float PacmanPlayer::getXpos() const{
    return xPos;
}

void PacmanPlayer::setXpos(float x_pos){
    xPos = x_pos;
}

void PacmanPlayer::setYpos(float y_pos){
    yPos = y_pos;
}
*/
PacmanPlayer::~PacmanPlayer(){}
