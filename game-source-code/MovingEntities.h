#ifndef MOVINGENTITIES_H
#define MOVINGENTITIES_H

#include "Grid.h"
#include "Direction.h"
#include "Position.h"

struct EntityDimensions{  // members in the struct are here so that they can be easily changed/modified in the specific entity
    const Grid grid_;
    float height = 15.0;
    float width = 15.0;
    float speed = 1.0;
    float maxWidth  = grid_.getWidth() - width;
    float minHeight = height;
    float minWidth = width;
    float maxHeight = grid_.getHeight() - height;
};

class MovingEntities{
public:
         Position move(Direction, const Position&);

         void setXPos(float&);

         void setYPos(float&);

         Position getPosition() const;

         ~MovingEntities(){}

private:
         Grid grid_;
         Direction dir_;
         Position position_;
         struct EntityDimensions dimensions_;
};

#endif // MOVINGENTITIES_H
