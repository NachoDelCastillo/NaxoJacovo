//
// Created by eys on 20/8/21.
//

#ifndef CARGAME_GAME_H
#define CARGAME_GAME_H

#include <iostream>
#include <string>
#include <vector>

#include "../View/TextureContainer.h"
#include "../View/Texture.h"
#include "../View/Box.h"
#include "../View/Font.h"

#include "GameObjects/Car.h"
#include "GameObjects/Rock.h"


using namespace std;

class Game{


private:
    string name;
    bool doExit;
    int roadLength;
    int width, height;
    Car *car = nullptr;
    Rock *rocks[20];

    TextureContainer *textureContainer;
    SDL_Renderer* renderer = nullptr;
    Font *font;

public:
    const unsigned int CAR_WIDTH = 100;
    const unsigned  int CAR_HEIGHT = 50;

    const unsigned int ROCK_WIDTH = 50;
    const unsigned  int ROCK_HEIGHT = 50;

    Game(string name, int width, int height, int roadLength);
    ~Game();

    void startGame();
    void update();
    void draw();

    void setUserExit();
    bool isUserExit();
    bool doQuit();

    int getWindowWidth();
    int getWindowHeight();

    void setDirection(int, bool);

    Point2D<int> getOrigin();

    string getGameName();

    void setRenderer(SDL_Renderer *renderer);
    void loadTextures();
    Texture *getTexture(TextureName name);
    SDL_Renderer *getRenderer();
    void renderText(string text, int x, int y, SDL_Color color={0,0,0});

    void drawInfo();

};


#endif //CARGAME_GAME_H
