#ifndef DEFS_H
#define DEFS_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;


class Shape{
	public:
	Shape();

	virtual float area();
	virtual float perimeter();
	virtual string get_type();
	virtual void print();

};

class Rectangle : public Shape{
	private:
	float width;
	float height;

	public:
	Rectangle(float w, float h);

	virtual float area();
	virtual float perimeter();
	virtual string get_type();
	virtual void print();

};

class Triangle : public Shape{
	private:
	float base;
	float height;

	public:
	Triangle(float b, float h);
	virtual float area();
	virtual float perimeter();
	virtual string get_type();
	virtual void print();

};

class Square : public Shape{
	private:
	float side;

	public:
	Square(float s);
	virtual float area();
	virtual float perimeter();
	virtual string get_type();
	virtual void print();

};

#endif
