#ifndef SplashScreen_H
#define Splashscreen_H

#include "PacmanGameControl.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Invalid_dimensions
{

};
class SplashScreen
{
public:
    SplashScreen();
    bool Validate_Dimensions(float width, float height);
    void Welcome (float width=800, float height=800);

    ~SplashScreen();

private:
    sf::RenderWindow window;
    PacmanGameControl control;
};

#endif
