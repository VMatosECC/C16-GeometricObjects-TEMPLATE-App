#pragma once
#include "GeometricObject.h"

template <typename T>
class Rectangle : public GeometricObject<T>
{
private:
    //Data Members
    T width;
    T height;

public:
    //Mutators - Setters
    void setWidth(T widthValue)   { width = widthValue; }
    void setHeight(T heightValue) { height = heightValue; }

    //Accessors - Getters
    T getWidth()  { return width; }
    T getHeight() { return height; }

    //Constructors
    Rectangle(string colorValue = "green", bool filledValue = true,
             T widthValue = 0, T heightValue = 0)
        : GeometricObject<T>(colorValue, filledValue)
    {
        setHeight(heightValue);
        setWidth(widthValue);
    }

    //User-Defined Methods
    string toString() {
        stringstream sout;
        sout << this
            << GeometricObject<T>::getColor() 
            << " Rectangle [Height: " << getHeight()
            << ", Width: " << getWidth()
            << ",\n\t" << GeometricObject<T>::toString()
            << ",\n\tArea: " << getArea()
            << ", Perimeter: " << getPerimeter()
            << "] Side-Type: " << typeid(width).name();;
        return sout.str();
    }

    //implementing pure virtual functions - makes my parent happy!
    T getArea()      override { return (getWidth() * getHeight()); }
    T getPerimeter() override { return 2 * (getWidth() + getHeight()); }


};

