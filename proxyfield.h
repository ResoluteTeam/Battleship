#ifndef PROXYFIELD_H
#define PROXYFIELD_H

#include "realfield.h"

class ProxyField
{
RealField *realField;
int id, size;
int x_pos;
static int next_id;

public:
       ProxyField(int pos, int sz)
       {
            id = next_id++;
            size = sz;
            realField = 0;                   
            x_pos = pos;
       }
       
       ~ProxyField()
       {
            delete realField;
       }
       
       void draw()
       {
            if(!realField)
                realField = new RealField(id);
            realField->draw(x_pos, size);
       }
};

#endif
