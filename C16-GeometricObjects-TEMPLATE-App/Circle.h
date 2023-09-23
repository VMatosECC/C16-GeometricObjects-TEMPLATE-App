#pragma once
#include "GeometricObject.h"


//HEADER Portion --------------------------------------------------
template <typename T>
class Circle : public GeometricObject<T>
{
private:
    //Data Members
    T radius;

public:
    //Mutators - Setters
    void setRadius(T radiusValue);

    //Accessors - Getters
    T getRadius();

    //Constructors
    Circle<T>(string color = "green", bool filledValue = true, T radius = 0);

    //User-Defined Methods
    string toString();

    //implementing pure virtual functions - makes my parent happy!
    T getArea() override;
    T getPerimeter() override;
      
};

//IMPLEMENTATION Section -------------------------------------------

template <typename T>
void Circle<T>::setRadius(T radiusValue) {
    radius = abs(radiusValue);
}

template <typename T>
T Circle<T>::getRadius() {
    return radius;
}

template <typename T>
Circle<T>::Circle(string colorValue, bool filledValue, T radiusValue)
    : GeometricObject<T>(colorValue, filledValue)
{
    setRadius(radiusValue);
}

template <typename T>
string Circle<T>::toString()
{
    stringstream sout;
    sout << this 
        << " Circle [ Radius: " << getRadius()
        << ", Color: " << GeometricObject<T>::getColor()
        << ", Filled: " << GeometricObject<T>::getFilled()
        << ",\n\t Parent " << GeometricObject<T>::toString() 
        << ",\n\t Area: " << getArea()
        << ", Perimeter: " << getPerimeter() 
        << " ]";
    return sout.str();
}

template <typename T>
T Circle<T>::getArea() 
{
    return (GeometricObject<T>::PI * getRadius() * getRadius());
}

template <typename T>
T Circle<T>::getPerimeter()
{
    return (2 * GeometricObject<T>::PI * getRadius());
}


