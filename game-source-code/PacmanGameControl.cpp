#include "PacmanGameControl.h"
#include "Grid.h"
#include "GameActiveScreen.h"
#include <iostream>

PacmanGameControl::PacmanGameControl(/*Grid& grid_*/){}

void PacmanGameControl::run(){

    GameActiveScreen active_screen;
    active_screen.viewScreen();
}

PacmanGameControl::~PacmanGameControl(){}
