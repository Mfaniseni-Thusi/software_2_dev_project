#include <SFML/Graphics.hpp>
#include <iostream>
#include "SplashScreen.h"
#include <SFML/Window.hpp>

using namespace std;

SplashScreen::SplashScreen() {}

void SplashScreen::Welcome (float width, float height)
{
    if (!Validate_Dimensions(width, height))
    {
        throw Invalid_dimensions{};
    }

    sf::RenderWindow window(sf::VideoMode(width, height), "Super Pac-Man", sf::Style::Default);
    window.clear(sf::Color(0, 0, 255));

    sf::Texture image;
    if(!image.loadFromFile("pacman_pic.jpg"))
        return;
    sf::Sprite welcomebackground;
    welcomebackground.setTexture (image);
    welcomebackground.setScale(800/1920.0, 800/1080.0 );
    window.draw (welcomebackground);


    sf::Font font;
    if (!font.loadFromFile("Cream Peach.ttf"))
        return;


    sf::Text title;
    title.setString("Welcome to the Super Pac-Man Game");
    title.setCharacterSize(40);
    title.setStyle(sf::Text::Bold);
    title.setFont(font);
    title.setPosition(120, 100);

    sf::Text instructions;
    instructions.setString(" How to play \n Press Enter To Start \n Press Q/q To Quit");
    instructions.setCharacterSize(28);
    instructions.setFont(font);
    instructions.setPosition(20, 150);


    window.draw(title);
    window.draw(instructions);
    window.display();
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
        switch(event.type){
            case sf::Event::EventType::Closed:
                window.close();
                break;

            case sf::Event::EventType::KeyPressed:
                if(event.key.code == sf::Keyboard::Key::Q){
                    window.close();
                }
                else if(event.key.code == sf::Keyboard::Key::Enter){
                    window.close();
                    control.run();
                }
                break;
                default:
                break;
        }
        }
    }

}

bool SplashScreen:: Validate_Dimensions(float width, float height)
{

    if (width>1600 && height>900)
    {
        return false;
    }

    if (width<=0 || height<=0)
    {
        return false;
    }

    return true;
}

SplashScreen::~SplashScreen() {}
