#include "ship.h"

Ship::Ship(int** fld, int sz)
{
    size = sz;
    field = fld;   
    dir = false;
}

void Ship::setCoordinates(int _x, int _y)
{
    x = _x;
    y = _y; 
}

int Ship::getX()
{
    return x;
}

int Ship::getY()
{
    return y;
}
       
void Ship::draw()
{

    for(int i = 0; i < size; i++)
    {
        if(dir)  
        {
            if(y + size < 10)
            {
                for(int j = 0; j < size; j++)
                    field[x][y+j] = 1;
            }
        }
        else
        {
            if(x + size < 10)
            {
                for(int j = 0; j < size; j++)
                    field[x+j][y] = 1;    
            }
        }
    }  
}
       
void Ship::rotate()
{
    dir = !dir;
}
