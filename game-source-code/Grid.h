#ifndef GRID_H
#define GRID_H

class Grid{
public:
    Grid(unsigned int width = 800, unsigned int height = 800);

    unsigned int getWidth() const;

    unsigned int getHeight() const;

    ~Grid();

private:
    unsigned int height_;
    unsigned int width_;
};

#endif // GRID_H
