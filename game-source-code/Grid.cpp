#include "Grid.h"

Grid::Grid(unsigned int width, unsigned int height) : width_{width}, height_{height} {}

unsigned int Grid::getWidth() const {
    return width_;
}

unsigned int Grid::getHeight() const {
    return height_;
}

Grid::~Grid(){}
