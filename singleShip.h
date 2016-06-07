#ifndef SINGLESHIP_H
#define SINGLESHIP_H

class SingleShip { //Реадизация Синглтона

public:
        static SingleShip& getInstance() {
               static SingleShip instance;
               return instance;
        }
        
        void setCoordinates(int _x, int _y);
        int getX();
        int getY();
       
        bool draw();
       
        bool check(int _x, int _y);
        void rotate();
        void setSize(int sz);
        void setField(int **fld, int mSize);

private:
        SingleShip() {}
        SingleShip(const SingleShip&);
//        SingleShip& operator=(SingleShip&);
        
        int** field;
        int matrixSize;
        int size;
        int x,y;
        bool dir;
        
};

#endif
