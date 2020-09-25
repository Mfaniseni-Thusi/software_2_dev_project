#ifndef GHOST_H
#define GHOST_H

#include "MovingEntities.h"
#include "Grid.h"
#include "Direction.h"
#include "Position.h"

struct GhostDimensions{
    Grid grid_;
    double height = 20.0;
    double width = 20.0;
    double speed = 9.0;
    float maxWidth  = grid_.getWidth() - width;
    float minHeight = 0;
    float minWidth = 0;
    float maxHeight = grid_.getHeight() - height;
    float newXPos = 0.0;
    float newYPos = 0.0;
};

class Ghost : public MovingEntities {
    public:
        Ghost(const Grid&);

        float getYpos() const;

        float getXpos() const;

        void setXpos(float x_pos);

        void setYpos(float y_pos);

        ~Ghost();

    private:
        Direction dir_;
        const Grid grid_;
        struct GhostDimensions dimensions_;
        float xPos = grid_.getWidth()/2;
        float yPos = grid_.getHeight()/2 - 20;
        Position position_;

};

#endif //GHOST_H
