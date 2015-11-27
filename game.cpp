#include "game.h"

Game::Game()
{
    initwindow(650,468,"Play BattleShip",100,100,true,true);
    SIZE = 10;
    
    playerField = new int* [SIZE];
    AIField = new int* [SIZE];
    
    for(int count = 0; count < SIZE; count++) {
            playerField[count] = new int[SIZE];
            AIField[count] = new int[SIZE];
    }       
    
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            playerField[i][j] = 0;
            AIField[i][j] = 0;
        }
    }
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
    setfillstyle(SOLID_FILL, COLOR(230,225,255));
    bar(0,0,getmaxx(),getmaxy());
        
        
    setcolor(COLOR(164,211,238));
    setlinestyle(SOLID_LINE, 0,NORM_WIDTH);
    for ( int i = 0; i < 25; i++ ) {
        line(i*26, 0, i*26, 468);
        line(0, i*26, 650, i*26);
    }
    
    setcolor(COLOR(0,0, 150));
    setlinestyle(SOLID_LINE, 0,THICK_WIDTH);
    for(int i = 0; i <= SIZE; i++) {
            line(26 + i*26, 52, 26 + i*26, 312);
            line(26, 52 + i*26, 286, 52 + i*26);
            
            line(364 + i*26, 52, 364 + i*26, 312);
            line(364, 52 + i*26, 624, 52 + i*26);
        }
    
    
    
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if ( playerField[i][j] == 1 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                bar(28 + i*26, 28 + (j+1)*26, 26 + i*26 + 25, 26 + (j+1)*26 + 25);
            }
            if ( playerField[i][j] == -1 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                bar(28 + i*26, 28 + (j+1)*26, 26 + i*26 + 25, 26 + (j+1)*26 + 25);
                line(28 + i*26, 28 + (j+1)*26, 26 + i*26 + 25, 26 + (j+1)*26 + 25);
                line(28 + i*26 + 22, 28 + (j+1)*26, 26 + i*26 + 1, 26 + (j+1)*26 + 25);
            }
            if ( playerField[i][j] == 2 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                fillellipse(28 + i*26 + 12, 28 + (j+1)*26 + 12, 5, 5);
            } 
        }   
    }

    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++) {
            if ( AIField[i][j] == -1 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                bar(366 + i*26, 28 + (j+1)*26, 364 + i*26 + 25, 26 + (j+1)*26 + 25);
                line(366 + i*26, 28 + (j+1)*26, 364 + i*26 + 25, 26 + (j+1)*26 + 25);
                line(366 + i*26 + 22, 28 + (j+1)*26, 364 + i*26 + 1, 26 + (j+1)*26 + 25);
            }
            if ( AIField[i][j] == 2 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                fillellipse(366 + i*26 + 12, 28 + (j+1)*26 + 12, 5, 5);
            } 
        }   
    }
    
    swapbuffers();
}

void Game::update()
{       
  
}

Game::~Game()
{
}
