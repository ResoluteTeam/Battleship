#include "compositeObjects.h"

CompositeObjects::CompositeObjects()
{
                                    
}

void CompositeObjects::draw()
{
        for(int i = 0; i < array.size(); i++)
        {
                array[i]->draw();
        }
}

void CompositeObjects::addObject(Object* p)
{
     array.push_back(p);
}

CompositeObjects::~CompositeObjects()
{
 for(int i = 0; i < array.size(); i++)
 {
         delete array[i];
 }
}
