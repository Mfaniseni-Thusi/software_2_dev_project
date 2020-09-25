#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "GameActiveScreen.h"

GameActiveScreen::GameActiveScreen(){}

void GameActiveScreen::viewScreen(){
    sf::RenderWindow window(sf::VideoMode(grid_.getWidth(), grid_.getHeight()), "Super Pac-Man", sf::Style::Default);
    sf::Event event;
    window.setFramerateLimit(10);
    sf::Texture playerTexture;
    sf::Texture ghostTexture;
    if(!playerTexture.loadFromFile("pac_.png")){
        std::cout << "Error loading pacman texture!" << std::endl;  // We must handle this error accordingly
    }
    if(!ghostTexture.loadFromFile("ghost_.png")){
        std::cout << "Error loading ghost texture!" << std::endl;  // We must handle this error accordingly
    }

    sf::Sprite playerSprite(playerTexture);
    sf::Rect<float> playerGlobalBounds = playerSprite.getGlobalBounds();
    playerSprite.setOrigin(sf::Vector2f(playerGlobalBounds.width/2, playerGlobalBounds.height/2));
    playerSprite.setPosition(playerControl.getPosition().getX_pos(), playerControl.getPosition().getY_pos());

    sf::Sprite ghostSprite(ghostTexture);
    ghostSprite.setPosition(ghostControl.getPosition().getX_pos(), ghostControl.getPosition().getX_pos());

    window.clear(sf::Color::Black);
    window.display();

    while(window.isOpen()) // poll events
        {
        while(window.pollEvent(event)){
            switch(event.type){
                case sf::Event::EventType::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if(event.key.code == sf::Keyboard::Key::Q){
                        window.close();
                    }

                    else if(event.key.code == sf::Keyboard::Key::Up){
                        dir_ = Direction::UP;
                        pos_ = playerControl.move(Direction::UP, playerControl.getPosition());  // under development
                        playerControl.setPosition(pos_);
                        playerSprite.setRotation(-90);
                        playerSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::Down){
                        dir_ = Direction::DOWN;
                        pos_ = playerControl.move(Direction::DOWN, playerControl.getPosition());  // under development
                        playerControl.setPosition(pos_);
                        playerSprite.setRotation(90);
                        playerSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::Left){
                        dir_ = Direction::LEFT;
                        pos_ = playerControl.move(Direction::LEFT, playerControl.getPosition());  // under development
                        playerControl.setPosition(pos_);
                        playerSprite.setRotation(180);
                        playerSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::Right){
                        dir_ = Direction::RIGHT;
                        pos_ = playerControl.move(Direction::RIGHT, playerControl.getPosition());  // under development
                        playerControl.setPosition(pos_);
                        playerSprite.setRotation(0);
                        playerSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }
/*
                    else if(event.key.code == sf::Keyboard::Key::E){
                        pos_ = ghostControl.move(Direction::UP);  // under development
                        ghostSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                        //playerSprite.setPosition(playerControl.position_.getX_pos(), playerControl.position_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::X){
                        pos_ = ghostControl.move(Direction::DOWN);  // under development
                        ghostSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::S){
                        pos_ = ghostControl.move(Direction::LEFT);  // under development
                        ghostSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }

                    else if(event.key.code == sf::Keyboard::Key::D){
                        pos_ = ghostControl.move(Direction::RIGHT);  // under development
                        ghostSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
                    }*/
                    break;
                default:
                break;

            }
            window.clear(sf::Color::Black);
            window.draw(playerSprite);
            window.draw(ghostSprite);
            window.display();

        }
        if(pos_.getX_pos() > 0 && pos_.getY_pos() > 0 && pos_.getX_pos() <= 790 && pos_.getY_pos() <= 790){
            pos_ = playerControl.move(dir_, pos_);
            playerControl.setPosition(pos_);
            playerSprite.setPosition(pos_.getX_pos(), pos_.getY_pos());
        }
        }
}

GameActiveScreen::~GameActiveScreen(){}
