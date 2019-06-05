#include "point.hpp"  

    Point::Point(){
        x_ = 0.0;
        y_= 0.0;
        value_ = 0;
    }
    
    Point::Point(float x, float y, int value){
        x_ = x;
        y_= y;
        value_ = value;
    }

    float Point::getX() const{
        return x_;
    }

    float Point::getY() const{
        return y_;
    }

    int Point::getValue() const{
        return value_;
    }
