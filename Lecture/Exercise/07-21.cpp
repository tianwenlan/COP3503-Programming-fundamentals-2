#include <string>
#include <iostream>
using namespace std;

class Shape
{
	public:
		virtual double area() = 0;
		virtual double perimeter() = 0;
};

class Square: public Shape
{
	public:
		Square(double);
		double area();
		double perimeter();
		double getSide();
		double setSide(double);
	
	public:
		double side;
};

double Square::area()
{
	return side*side;
}

double Square::perimeter()
{
	return 4*side;
}

double getSide()
{
}

doulbe setSide(double)
{
}

Square::Square(double l)
{
	side = l;
}

int main()
{
	Square s1(3);
	Square s2(5);

	cout << "area: " << s1.area() << endl;
	cout << "perimeter: " << s1.perimeter() << endl;

	cout << "area: " << s2.area() << endl;
	cout << "perimeter: " << s2.perimeter() << endl;

}

