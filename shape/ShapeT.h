#ifndef SHAPE
#define SHAPE

#include <string>
using namespace std;

template <typename U>
class Shape
{
private:
protected:
  string color;
  bool filled;
  U identifier;

public:
  Shape();
  Shape(const string& color, const bool filled, const U& identifier);
  string getColor() const;
  void setColor(const string& color);
  U getIdentifier() const;
  void setIdentifier(const U& identifier);
  bool isFilled() const;
  void setFilled(const bool filled);
  virtual string toString() const;
};


template <typename U>
Shape<U>::Shape()
{
  color = "white";
  filled = false;
}

template <typename U>
Shape<U>::Shape(const string& color, const bool filled, const U& identifier)
{
  this->color = color;
  this->filled = filled;
  this->identifier = identifier;
}

template <typename U>
string Shape<U>::getColor() const
{
  return color;
}

template <typename U>
void Shape<U>::setColor(const string& color)
{
  this->color = color;
}

template <typename U>
U Shape<U>::getIdentifier() const
{
  return identifier;
}

template <typename U>
void Shape<U>::setIdentifier(const U& identifier)
{
  this->identifier = identifier;
}

template <typename U>
bool Shape<U>::isFilled() const
{
  return filled;
}

template <typename U>
void Shape<U>::setFilled(const bool filled)
{
  this->filled = filled;
}

template <typename U>
string Shape<U>::toString() const
{
  string s;
  s = (filled ? "Filled " : "Unfilled ") + color + " shape"; 
  return s;
}


#endif
