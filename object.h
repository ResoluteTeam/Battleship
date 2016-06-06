#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
       virtual void draw() {}
       virtual ~Object() {}
       virtual void addObject(Object* p){}
};

#endif
