#include "MovingEntities.h"
#include <iostream>

Position MovingEntities::move(Direction dir, const Position& entityPosition){
    position_ = entityPosition;
    dir_ = dir;
    switch(dir_){
        case Direction::UP:
            if(position_.getY_pos() >= dimensions_.minHeight && position_.getY_pos() >= dimensions_.minHeight){
                position_.setY_pos(position_.getY_pos() - dimensions_.speed);
                std::cout << position_.getY_pos() << std::endl;
            }
            break;

        case Direction::DOWN:
            if(position_.getY_pos() <= dimensions_.maxHeight && position_.getY_pos() <= dimensions_.maxHeight){
                position_.setY_pos(position_.getY_pos() + dimensions_.speed);
                std::cout << position_.getY_pos() << std::endl;
            }
            break;

        case Direction::LEFT:
            if(position_.getX_pos() >= dimensions_.minWidth && position_.getX_pos() >= dimensions_.minWidth){
                position_.setX_pos(position_.getX_pos() - dimensions_.speed);
                std::cout << position_.getX_pos() << std::endl;
            }
            break;

        case Direction::RIGHT:
            if(position_.getX_pos() <= dimensions_.maxWidth && position_.getX_pos() <= dimensions_.maxWidth){
                position_.setX_pos(position_.getX_pos() + dimensions_.speed);
                std::cout << position_.getX_pos() << std::endl;
            }
            break;

        default:
        break;
    }
    return position_;
}

void MovingEntities::setXPos(float &xPos){
         position_.setX_pos(xPos);
}

void MovingEntities::setYPos(float &yPos){
         position_.setY_pos(yPos);
}

Position MovingEntities::getPosition() const{
         return position_;
}
