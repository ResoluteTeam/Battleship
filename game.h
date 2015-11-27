#ifndef GAME_H
#define GAME_H

#include "button.h"
#include "label.h"
#include "graphics.h"
#include "iostream"
#include "vector"


class Game
{
public:
    Game();
    ~Game();
    int start();

private:
    void processEvents();
    void render();
    void update();
    
    int** playerField;
    int** AIField;
    int SIZE;
    
    bool exit;
};

#endif // GAME_H
