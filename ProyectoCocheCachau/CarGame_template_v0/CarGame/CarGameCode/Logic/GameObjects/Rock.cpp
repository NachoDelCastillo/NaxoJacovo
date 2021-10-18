//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Car::Car(Game* game) {
    this->game = game;
    texture = nullptr;
}

void Car::setDimension(int width, int height) {
    w = width;
    h = height;
}

void  Car::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
}

void Car::setCarMovement(int direction, bool activate) {

    switch (direction)
    {
    case 0:
        carUp = activate;
        break;
    case 1:
        carDown = activate;
        break;
    case 2:
        carLeft = activate;
    case 3:
        carRight = activate;
    default:
        break;
    }


}

void Car::update() {

    int despY = 0;

    if (carLeft)
    {
        HSPEED *= DECELERATION;

        if (HSPEED <= 0.1f)
            HSPEED = 0;
    }
    else if (carRight)
    {
        if (HSPEED == 0)
            HSPEED = 1;

        HSPEED *= ACCELERATION;

        if (HSPEED >= MAX_SPEED)
            HSPEED = MAX_SPEED;
    }
    cout << HSPEED << endl;


    if (carUp && getY() > 0 + game->CAR_HEIGHT)
    {
        despY = -VSPEED;
    }
    else if (carDown && getY() < game->getWindowHeight() - (game->CAR_HEIGHT / 2))
    {
        despY = VSPEED;
    }

    pos = Point2D<double>(getX() + HSPEED, getY() + despY);
}

Car::~Car() {};

void Car::draw() {
    drawTexture(game->getTexture(carTexture));
}


void Car::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}


SDL_Rect Car::getCollider() {
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}