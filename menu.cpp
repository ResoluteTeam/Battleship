#include "menu.h"

Menu::Menu(){
    initwindow(640,480,"BattleShip",100,100,true,true); 
    
    logo.setText("BattleShip");
    logo.setColor(COLOR(200,225,255), COLOR(102,205,170));
    logo.setPosition(110, 50);
    logo.setSize(0);
    
    startBtn.setCaption("Start!");
    startBtn.setColor(COLOR(200,225,255), COLOR(102,205,170));
    startBtn.setPosition(30,300);
    
    exitBtn.setCaption("Exit!");
    exitBtn.setColor(COLOR(200,225,255), COLOR(102,205,170));
    exitBtn.setPosition(350,300);
    
    buttonIndex = 0;
    startBtn.setFocus(true);
    
    blinkVal = 100000;   
    flag = true;  
    settextstyle(10, 0, 7);
}

int Menu::start(){
    exit = false;
    status = 1;
    int frames = 500, i = 0;

    
    while(!exit)
    {
        while(i < frames){
            processEvents();
            update();
            i++;
        }   
        render(); 
        i = 0;
    }
    closegraph();
    return status;
}

void Menu::render(){
    cleardevice();  
    setfillstyle(SOLID_FILL, COLOR(200,225,255));
    bar(0,0,getmaxx(),getmaxy());
    setbkcolor(COLOR(200,225,255));

    setcolor(COLOR(126, 192,238));
    logo.draw();

    startBtn.draw();
    exitBtn.draw();
    swapbuffers();
}

void Menu::update(){
    time++;
    if(time > blinkVal)
    {
        logo.setColor(bkcolor, flag);
        flag = !flag;
        time = 0;
    }
}

void Menu::processEvents(){
    if(kbhit())
    {
        char key = getch();

        if(key == '\r')
        {
            if(buttonIndex)
            {
                status = 2;
                exit = true;
            }
            else
            {
                status = 1;
                exit = true;
            }
        }
        
        if(key == 27)
        {
            exit = true;
            status = 2;
        }
        
        if(key == NULL)
        {
            char keychar = getch();
            switch(keychar)
            {
                case 'M': //arrow right
                {
                    if(buttonIndex == 1)
                        buttonIndex--;
                    else if(buttonIndex == 0)
                        buttonIndex++;    
                }
                    break;
                
                case 'K': //arrow left
                {
                    if(buttonIndex == 0)
                        buttonIndex = 1;
                    else
                        buttonIndex--;  
                }
                    break;
            }
            
            if(buttonIndex == 1)
            {
                exitBtn.setFocus(true);
                startBtn.setFocus(false);
            }
            else
            {
                exitBtn.setFocus(false);
                startBtn.setFocus(true);
            }
        }
    }    
}
