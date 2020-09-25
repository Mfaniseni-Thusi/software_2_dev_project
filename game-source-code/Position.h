#ifndef POSITION_H
#define POSITION_H

class Position{
public:
    Position();

    Position(float, float);

    void setX_pos(float &&xPos);  // X setter with rvalue reference

    void setY_pos(float &&yPos);  // Y setter with rvalue reference

    void setX_pos(float &xPos);  // X setter with lvalue reference

    void setY_pos(float &yPos);  // Y setter with lvalue reference

    float getX_pos() const;

    float getY_pos() const;

    Position operator-(const Position& rhs);

    bool operator==(const Position& rhs) const;

    ~Position();

private:
    float xPos_;
    float yPos_;

};
#endif // POSITION_H
