#ifndef GAMEACTIVESCREEN_H
#define GAMEACTIVESCREEN_H

#include "PacmanPlayer.h"
#include "Ghost.h"
#include "Direction.h"
#include "Position.h"

class GameActiveScreen{
public:
    GameActiveScreen();

    void viewScreen();

    ~GameActiveScreen();

private:
    const Grid grid_;
    PacmanPlayer playerControl = PacmanPlayer{grid_};
    Ghost ghostControl = Ghost{grid_};
    Position pos_;
    Direction dir_;
};

#endif // GAMEACTIVESCREEN_H
