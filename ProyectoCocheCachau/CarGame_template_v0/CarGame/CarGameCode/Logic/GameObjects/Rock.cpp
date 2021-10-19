//
// Created by eys on 21/8/21.
//

#include "Car.h"
#include "../Game.h"

Rock::Rock(Game* game) {
    this->game = game;
    texture = nullptr;
}

void Rock::setDimension(int width, int height) {
    w = width;
    h = height;
}

void  Rock::setPosition(double x, double y) {
    pos = Point2D<double>(x, y);
}

void Rock::update() {

    int despY = 0;

    //if (carLeft)
    //{
    //    HSPEED *= DECELERATION;

    //    if (HSPEED <= 0.1f)
    //        HSPEED = 0;
    //}
    //else if (carRight)
    //{
    //    if (HSPEED == 0)
    //        HSPEED = 1;

    //    HSPEED *= ACCELERATION;

    //    if (HSPEED >= MAX_SPEED)
    //        HSPEED = MAX_SPEED;
    //}
    //cout << HSPEED << endl;


    //if (carUp && getY() > 0 + game->CAR_HEIGHT)
    //{
    //    despY = -VSPEED;
    //}
    //else if (carDown && getY() < game->getWindowHeight() - (game->CAR_HEIGHT / 2))
    //{
    //    despY = VSPEED;
    //}

   // pos = Point2D<double>(getX() + HSPEED, getY() + despY);
}

Rock::~Rock() {};

void Rock::draw() {
    drawTexture(game->getTexture(rockTexture));
}


void Rock::drawTexture(Texture* texture) {
    int dX = game->getOrigin().getX();
    int dY = game->getOrigin().getY();

    SDL_Rect c = getCollider();
    SDL_Rect textureBox = { c.x + dX, c.y + dY, c.w, c.h };
    texture->render(textureBox);
}


SDL_Rect Rock::getCollider() {
    return { int(getX() - getWidth()),
             int(getY() - getHeight() / 2),
             getWidth(),
             getHeight() };
}