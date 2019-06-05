#ifndef __POINT__
#define __POINT__

#include <iostream>

class Point{
    public:
        //Construtors
        Point();
        Point(float x, float y, int value);

        // getMethods
        float getX() const;
        float getY() const;
        int getValue() const;
    
    private:
        float x_;
        float y_;
        int value_;
};

#endif