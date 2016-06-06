#ifndef COMPOSITEOBJECTS_H
#define COMPOSITEOBJECTS_H

#include <vector>
#include "object.h"

class CompositeObjects: public Object 
{
public:
        CompositeObjects();
        virtual void draw();
        void addObject(Object* p);
        ~CompositeObjects();
      
private:
        std::vector<Object*> array;
};

#endif
