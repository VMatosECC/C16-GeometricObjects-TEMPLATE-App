#pragma once
#include "Rectangle.h"

template <typename T>
class Square : public Rectangle<T>
{
private:
    //data member(s)
    T side;
    
public:
    //Constructor(s)
    Square(string colorValue = "green", bool filledValue = true, T sideValue = 0)
        : Rectangle<T>(colorValue, filledValue, sideValue, sideValue)
    {
        side = sideValue;
    }
    
    //Destructor
    ~Square() { cout << "Square destructor " << this << endl; }
    
    //Mutator-Accessor(s)
    T setSide(T sideVal)  { return 4 * side; }
    T getSide() { return side; }
    
    //User-defined methods
    string toString() {
        stringstream sout;
        sout << this << " Square [Side: " << side
            << ", Color: "     << this->getColor()
            << ", Area: "      << getArea()
            << ", Perimeter: " << getPerimeter()
            << "] Side-Type: " <<  typeid(side).name();
        return sout.str();
    }

    //implementing pure virtual functions - makes my parent happy!
    T getArea()      override { return side * side; }
    T getPerimeter() override { return 4 * side; }
};


