#ifndef APPLICATION_H
#define APPLICATION_H

#include "game.h"
#include "menu.h"

enum gameState{
         MENU,
         GAME,
         EXIT
};

class Application{
      
public:
        Application();
        int run();
       
private:
        gameState status;
};

#endif
