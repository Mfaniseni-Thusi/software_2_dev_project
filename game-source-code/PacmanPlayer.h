#ifndef PACMANPLAYER_H
#define PACMANPLAYER_H

#include "MovingEntities.h"
#include "Grid.h"
#include "Direction.h"
#include "Position.h"


struct PlayerDimensions{
    Grid grid_;
    double height = 20.0;
    double width = 20.0;
    double speed = 1.0;
};

class PacmanPlayer : public MovingEntities{
    public:
        PacmanPlayer(const Grid& grid_);

        Position getPosition() const;

        void setPosition(Position&);

        ~PacmanPlayer();

    private:
        Direction dir_;
        const Grid grid_;
        struct PlayerDimensions dimensions_;
        Position position_{static_cast<float>(grid_.getWidth()/2) , static_cast<float>(grid_.getHeight()/2)};

};

#endif // PACMANPLAYER_H
