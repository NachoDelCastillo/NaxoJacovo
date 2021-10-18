//
// Created by eys on 20/8/21.
//

#include "Game.h"

Game::Game(string name, int width, int height, int roadLength) {
    this->name = name;
    this->roadLength = roadLength;
    this->width = width;
    this->height = height;
    doExit = false;
    font = new Font("../Images/Monospace.ttf", 12);
}

void Game::startGame() {
    car = new Car(this);
    car->setDimension(CAR_WIDTH, CAR_HEIGHT);
    car->setPosition(car->getWidth(), height/ 2.0);


    for (int i = 0; i < 20; i++)
    {
       // rocks[i] = new Rock();
    }
}

string Game::getGameName() {
    return name;
}

Game::~Game() {
    cout << "[DEBUG] deleting game" << endl;
}

void Game::update(){
    car->update();
}


// CAR MOVEMENT

// Directions = {
//      0 = up;
//      1 = down;
//      2 = left;
//      3 = right;

void Game::setDirection(int direction, bool activate) 
{
    car->setCarMovement(direction, activate);
}

void Game::draw(){
    car->draw();
    drawInfo();
}

void Game::drawInfo() {
    int x = font->getSize() / 2;
    int y = font->getSize() / 2;

    SDL_Rect rect = {0, 0, getWindowWidth(),
                     int(font->getSize() * 1.8)};
    Box(rect, BLACK).render(renderer);

    string s = "Pos: " + to_string(int(car->getX())) + " "
               + to_string(int(car->getY()));
    renderText(s, x, y);
}

void Game::setUserExit() {
    doExit = true;
}

bool Game::isUserExit() {
    return doExit;
}

int Game::getWindowWidth(){
    return width;
}

int Game::getWindowHeight() {
    return height;
}

SDL_Renderer *Game::getRenderer() {
    return renderer;
}

void Game::setRenderer(SDL_Renderer *_renderer) {
    renderer = _renderer;
}

void Game::loadTextures() {
    if(renderer == nullptr)
        throw string("Renderer is null");

    textureContainer = new TextureContainer(renderer);
}

void Game::renderText(string text, int x, int y, SDL_Color color){
    font->render(renderer, text.c_str(), x, y, color);
}

bool Game::doQuit() {
    return isUserExit();
}

Texture *Game::getTexture(TextureName name) {
    return textureContainer->getTexture(name);
}

Point2D<int> Game::getOrigin() {
    return {int(-(car->getX() - car->getWidth())), 0};
}