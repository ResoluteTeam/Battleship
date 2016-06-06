#include "application.h"

Application::Application()
{

}

int Application::run(){

   status = MENU;
    
    while(status != EXIT)
    {
        switch(status)
        {
            case MENU:
                {
                Menu menu;
                status = static_cast<gameState>(menu.start());
            }
            break;
            
            case GAME:
                {
                Game game;
                status = static_cast<gameState>(game.start());
            }
            break;
            
            case EXIT:
                break;
        }   
    } 
    
    return 0;
    
}
