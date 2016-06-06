#ifndef REALFIELD_H
#define REALFIELD_H

class RealField
{
int id;

public:
       RealField(int i)
       {
            id = i;
       }
       
       void draw(int pos, int size)
       {
            for(int i = 0; i <= size; i++) {
                    line(pos + i*26, 52, pos + i*26, 312);
                    line(pos, 52 + i*26, pos + 260, 52 + i*26);
            }
       }
private:

};

#endif
