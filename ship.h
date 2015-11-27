#ifndef SHIP_H
#define SHIP_H

#include "vector"

class Ship{

public:
        Ship(int** fld, int sz);
    
        void setCoordinates(int _x, int _y);
        int getX();
        int getY();
       
        void draw();
       
        void rotate();
       
private:
        int** field;
        int size;
        int x,y;
        bool dir;      
      
};

#endif
