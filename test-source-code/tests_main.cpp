#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SplashScreen.h"
#include "PacmanPlayer.h"
#include "Grid.h"
#include "Direction.h"
#include "PacmanGameControl.h"
#include <iostream>

//_____TEST TO CHECK IF SCREEN SIZE IS EXCEEDD_______
TEST_CASE("The screen size is exceeded")
{
SplashScreen screen;
CHECK_THROWS_AS (screen.Welcome(1800,1000), Invalid_dimensions);
}

//_____TEST TO CHECK IF SCREEN SIZE IS INVALID_______
TEST_CASE("The screen size is invalid")
{
SplashScreen screen;
CHECK_THROWS_AS (screen.Welcome(-1.f,-2.f), Invalid_dimensions);
}

//_____TEST TO CHECK IF SCREEN SIZE IS VALID_______
TEST_CASE("The screen size is valid")
{
SplashScreen screen;
CHECK (screen.Validate_Dimensions(1.f, 2.f));
}


TEST_CASE("Pacman can move up")
{
    const Grid grid_;
    const Grid* gridPtr = & grid_;
    PacmanPlayer player = PacmanPlayer{*gridPtr};
    float prevY = player.getYpos();
    player.move(Direction::UP);
    CHECK((prevY - 10) == player.getYpos());
}

TEST_CASE("PacmanPlayer can move down")
{
    const Grid grid_;
    const Grid* gridPtr = & grid_;
    PacmanPlayer player = PacmanPlayer{*gridPtr};
    float prevY=player.getYpos();
    player.move(Direction::DOWN);
    CHECK(prevY + 10 == player.getYpos());
}

TEST_CASE("PacmanPlayer can move left")
{
    const Grid grid_;
    const Grid* gridPtr = & grid_;
    PacmanPlayer player = PacmanPlayer{*gridPtr};
    float prevX=player.getXpos();
    player.move(Direction::LEFT);
    CHECK(prevX - 10 == player.getXpos());
}

TEST_CASE("PacmanPlayer can move right")
{
    const Grid grid_;
    const Grid* gridPtr = & grid_;
    PacmanPlayer player = PacmanPlayer{*gridPtr};
    float prevX=player.getXpos();
    player.move(Direction::RIGHT);
    CHECK(prevX + 10 == player.getXpos());

}
