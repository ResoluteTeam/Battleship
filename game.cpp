#include "game.h"

Game::Game()
{
    initwindow(650,468,"Play BattleShip",100,100,true,true);

    settextstyle(10, 0, 9);
    setbkcolor(COLOR(200,225,255));
    
    label = new Label();
    label->setColor(COLOR(200,225,255), COLOR(102,205,170));
    label->setVisible(false);
    label->setPosition(40, 150);
    
    
    settextstyle(7, 0, 3);
    setbkcolor(COLOR(230,225,255));
    
    republic = new Label();
    republic->setColor(COLOR(200,225,255), COLOR(0,0,150));
    republic->setPosition(24, 30);
    republic->setText("R e s p u b l i k a");
    republic->setVisible(true);
    
    l1 = new Label();
    l1->setColor(COLOR(200,225,255), COLOR(0,0,150));
    l1->setVisible(true);
    
    republic2 = new Label();
    republic2->setColor(COLOR(200,225,255), COLOR(0,0,150));
    republic2->setPosition(364, 30);
    republic2->setText("R e s p u b l i k a");
    republic2->setVisible(true);
    
    stat = new Label();
    stat->setColor(COLOR(200,225,255), COLOR(0,0,150));
    stat->setPosition(145, 342);
    stat->setText("Set up ships...");
    stat->setVisible(true);
    
    info = new Label();
    info->setColor(COLOR(200,225,255), COLOR(0,0,150));
    info->setPosition(145, 394);
    info->setText("Press Space to rotate");
    info->setVisible(true);
    
    SIZE = 10;
    
    status = false;
    waitForPlayer = false;
    
    playerWin = false;
    AIWin = false;
    
    srand(time(0));
    
    playerField = new int* [SIZE];
    AIField = new int* [SIZE];
    matrix = new int* [4];
    
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
    
    for ( int i = 0; i < 4; i++ ) {
            matrix[i] = new int[4];
    }
    
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            matrix[i][j] = 0;
        }
    }
    ship = new Ship(matrix, 1);
    
    initAIField();
    
    ships.push_back(1);
    ships.push_back(1);
    ships.push_back(1);
    ships.push_back(1);
    
    ships.push_back(2);
    ships.push_back(2);
    ships.push_back(2);
    
    ships.push_back(3);
    ships.push_back(3);
    
    ships.push_back(4);
    

}

int Game::start()
{
    exit = false;
    
    int frames = 50000, i = 0;
    
    while(!exit) {
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
    if(kbhit() || ismouseclick(WM_LBUTTONDOWN))
    {      
        if(kbhit()) {
            char key = getch();
            if(key == 27)
            {
                exit = true;
            } 
            if ( key == ' ' ) {
                if ( !status ) {
                    if ( waitForPlayer ) {
                        for (int i = 0; i < 4; i++ ) {
                            for ( int j = 0; j < 4; j++ ) {
                                matrix[i][j] = 0;
                            }
                        }
                        
                        ship->rotate();
                        ship->draw();
                        
                    }
                }
            }
        } else {
            int mouseX, mouseY;
            int x, y;
            getmouseclick(WM_LBUTTONDOWN, mouseX, mouseY);
            
            
            if ( status ) {
                if (waitForPlayer) {
                    if ( mouseX > 364 && mouseX < 624 && mouseY > 56 && mouseY < 312 ) {
                        std::cout << "X:" << mouseX << "Y:" << mouseY << std::endl;
                        
                        double a, b, xx, yy;
                    
                        a = mouseX/26;
                        b = mouseY/26;
                    
                        std::modf(a, &xx);
                        std::modf(b, &yy);
                        std::cout << "Position: " << a << ":" << b << std::endl;
                    
                        x = (int)xx - 1 - 13;
                        y = (int)yy - 1 - 1;
                        
                        if ( shoot(x, y, AIField) ) {
                            waitForPlayer = false;
                        }
                    }
                    
                    
                }
            } else {
                if (waitForPlayer) {
                    if ( mouseX > 26 && mouseX < 294 && mouseY > 56 && mouseY < 312 ) {
                        std::cout << "X:" << mouseX << "Y:" << mouseY;
                        
                        double a, b, xx, yy;
                        
                        a = mouseX/26;
                        b = mouseY/26;
                    
                        std::modf(a, &xx);
                        std::modf(b, &yy);
                        std::cout << "Position: " << a << ":" << b << std::endl;
                        
                    
                        x = (int)xx - 1;
                        y = (int)yy - 1 - 1;
                        
                        ship->setField(playerField, 10);
                        ship->setCoordinates(x, y);
                        
                        
                        if ( ship->draw() ) {
                            ships.pop_back();
                        }
    
                        waitForPlayer = false;
                    }
                }
            }
        }
    }
}

void Game::render()
{
    setfillstyle(SOLID_FILL, COLOR(230,225,255));
    bar(0,0,getmaxx(),getmaxy());
    
    settextstyle(7, 0, 3);
    setbkcolor(COLOR(230,225,255)); 
           
    republic->draw();
    republic2->draw();
    
    
    
    for ( int i = 0; i < 10; i++ ) {
        l1->setPosition(315, 56 + i*26);
        char ww[3];
        itoa(i + 1,ww,10);
        l1->setText(ww);
        l1->draw();
    }
    
    setcolor(COLOR(164,211,238));
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
    for ( int i = 0; i < 25; i++ ) {
        line(i*26, 0, i*26, 466);
        line(0, i*26, 648, i*26);
    }
    
    
    setcolor(COLOR(0,0, 150));
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    for(int i = 0; i <= SIZE; i++) {
        line(26 + i*26, 52, 26 + i*26, 312);
        line(26, 52 + i*26, 286, 52 + i*26);
        
        line(364 + i*26, 52, 364 + i*26, 312);
        line(364, 52 + i*26, 624, 52 + i*26);
        
    }
    
    for ( int i = 0; i <= 4; i++ ) {
            line(26 + i*26, 338, 26 + i*26, 442);
            line(26, 338 + i*26, 130, 338 + i*26);
    }
    
    for ( int i = 0; i < 4; i++ ) {
        for ( int j = 0; j < 4; j++ ) {
            if ( matrix[i][j] == 1 ) {
                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
                bar(28 + i*26, 314 + (j+1)*26, 26 + i*26 + 25, 312 + (j+1)*26 + 25);
            }
        }
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
            
//            if ( AIField[i][j] == 1 ) {
//                setfillstyle(SOLID_FILL, COLOR(104, 131, 139));
//                bar(366 + i*26, 28 + (j+1)*26, 364 + i*26 + 25, 26 + (j+1)*26 + 25);
//            }
        }   
    }
    settextstyle(10, 0, 2);
    setbkcolor(COLOR(230,225,255));
    info->draw();
    stat->draw();
    
    settextstyle(10, 0, 9);
    setbkcolor(COLOR(200,225,255));
    label->draw();
    
    swapbuffers();
}

void Game::update()
{
    if ( status ) {
        stat->setText("Shoot! ");
        info->setText(" ");
        if(!waitForPlayer)
        {
            if ( shoot(rand()%10, rand()%10, playerField) ) {
                waitForPlayer = true;
            }
        }
        playerWin = true;
        AIWin = true;
        for ( int i = 0; i < SIZE; i++ ) {
            for ( int j = 0; j < SIZE; j++ ) {
                if ( AIField[i][j] == 1 ) {
                    playerWin = false;
                }
                
                if ( playerField[i][j] == 1 ) {
                    AIWin = false;
                }
            }
        }
        
        if ( playerWin ) {
            label->setText("You WIN!!!");
            label->setVisible(true);
            
        }
        
        if ( AIWin ) {
            label->setText("You LOSE!!!");
            label->setVisible(true);
        }
        
        
    } else {
        if ( !waitForPlayer ) {
            if ( !ships.empty() ) {
                ship->setField(matrix, 4);
                ship->setSize(ships.back());
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        matrix[i][j] = 0;
                ship->setCoordinates(0,0);
                ship->draw();
                waitForPlayer = true;
            } else { 
                status = true;
                waitForPlayer = true;
            }
        }
    }
}

void Game::initAIField() 
{
    ships.push_back(1);
    ships.push_back(1);
    ships.push_back(1);
    ships.push_back(1);
    
    ships.push_back(2);
    ships.push_back(2);
    ships.push_back(2);
    
    ships.push_back(3);
    ships.push_back(3);
    
    ships.push_back(4);
    
    ship->setField(AIField, 10);
    while ( !ships.empty() ) {
        ship->setSize(ships.back());
        ship->setCoordinates(rand()%9,rand()%9);
        bool rotate = rand()%2;
        
        if(rotate)
        {
            ship->rotate();
        }
        if(ship->draw())
        {
            ships.pop_back();
        }
    }
}

bool Game::shoot(int _x, int _y, int** fld) 
{
    if ( fld[_x][_y] != 2 && fld[_x][_y] != -1 ) {
        if ( fld[_x][_y] == 0 ) {
            fld[_x][_y] = 2;
            return true;
        }
        if ( fld[_x][_y] == 1 ) {
            fld[_x][_y] = -1;
            return false;
        }
    } else { 
        return false;
    }
}

bool Game::checkIfDead(int _x, int _y, int** fld)
{
    std::vector<pos*> ppos;
    
    pos* temp;
    
    int i = _x;
    int j = _y;
    bool check = false;
    
    while( fld[i][j+1] != 0 || fld[i][j+1] != 2 ) {
        if (j < 8) {
                if ( fld[i][j+1] == 1 || fld[i][j+1] == -1 ) {
                    temp = new pos;
                    temp->x = i;
                    temp->y = j+1;
                    
                    ppos.push_back(temp);
                }
            } else {
                break;
        }
        j++;
    }
    
    i = _x;
    j = _y;
    
    while( fld[i][j-1] != 0 || fld[i][j-1] != 2 ) {
        if (j > 1) {
            if ( fld[i][j-1] == 1 || fld[i][j-1] == -1 ) {
            
                temp = new pos;
                temp->x = i;
                temp->y = j-1;
                
                ppos.push_back(temp);
            } else {
                break;
            }
            
        }
        j--;
    }
    
    i = _x;
    j = _y;
    
    while( fld[i+1][j] != 0 || fld[i+1][j] != 2 ) {
        if (i < 8) {
            if ( fld[i+1][j] == 1 || fld[i+1][j] == -1 ) {
             
                temp = new pos;
                temp->x = i+1;
                temp->y = j;
                
                ppos.push_back(temp);
            }
        } else {
            break;
        }
        i++;
    }
    
    i = _x;
    j = _y;
    
    while( fld[i-1][j] != 0 || fld[i-1][j] != 2 ) {
        if (i > 1) { 
            if ( fld[i-1][j] == 1 || fld[i-1][j] == -1 ) {
            
                temp = new pos;
                temp->x = i-1;
                temp->y = j;
                
                ppos.push_back(temp);
            }
        } else {
            break;
        }
        i--;
    }
    
    
    while (!ppos.empty()) {
        int posX = ppos.back()->x - 1;
        int posY = ppos.back()->y - 1;
        ppos.pop_back();
        for(int i = 0; i < 3; i++) 
            for(int j = 0; j < 3; j++)
            {
                if(posX + i < 0 || posY + j < 0 || posX + i > 9 || posY + j > 9)
                {
     
                }
                else 
                {
                    if(fld[posX + i][posY + j] == 0)  
                         fld[posX + i][posY + j] == 2;
                }
            }    
    }
}

Game::~Game()
{
}
