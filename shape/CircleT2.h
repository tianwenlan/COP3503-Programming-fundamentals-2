#include <string>
#include <sstream>
#include "ShapeT.h"

template <typename U, typename T>
class Circle : public Shape<U>
{
  private:
    T radius;
  public:
    Circle();
    Circle(const T radius);
    Circle(const T radius, const string &color, const bool filled, const U& identifier);
    
    T getRadius() const;
    void setRadius(T radius);
    double getArea() const;
    double getPerimeter() const;
    virtual string toString() const;
    //string toString() const override;
};

template <typename U, typename T>
Circle<U,T>::Circle()
{
  radius = 1;
}

template <typename U, typename T>
Circle<U,T>::Circle(const T radius)
{
  this->setRadius(radius);
}

template <typename U, typename T>
Circle<U,T>::Circle(const T radius, const string &color, const bool filled, const U& identifier)
{
  this->setRadius(radius);
  this->color = color;
  this->filled = filled;
  this->identifier = identifier;
}
    
template <typename U, typename T>
T Circle<U,T>::getRadius() const
{
  return(radius);
}

template <typename U, typename T>
void Circle<U,T>::setRadius(T radius)
{
  this->radius = (radius > 0 ? radius : 0);
}

template <typename U, typename T>
double Circle<U,T>::getArea() const
{
  return(radius * radius * 355.0 / 113.0);
}

template <typename U, typename T>
double Circle<U,T>::getPerimeter() const
{
  return(2 * radius * 355.0 / 113.0);
}

template <typename U, typename T>
string Circle<U,T>::toString() const
{
  stringstream ss;
  ss << "Id: " << this->getIdentifier() << " - "
     << (this->isFilled() ? "Filled " : "Unfilled ") << this->getColor() 
     << " circle of radius " << radius;
  return ss.str();
}


