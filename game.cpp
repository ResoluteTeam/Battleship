#include "game.h"

Game::Game()
{
initwindow(640,480,"Play AntiTetris",100,100,true,true);

}

int Game::start()
{
    exit = false;
    
    int frames = 50000, i = 0;
    
    while(!exit)
    {
        delay(100);
        processEvents();
        update();
        render(); 

    }
    closegraph();
    return 0;
}

void Game::processEvents()
{
    if(kbhit())
    {      
        char key = getch();
        if(key == 27)
        {
            exit = true;
        }

        if(key == '\r')
        {
            
        }
    }
}

void Game::render()
{
    rectangle(0,0,100,100);//test
}

void Game::update()
{       
  
}

Game::~Game()
{
}
