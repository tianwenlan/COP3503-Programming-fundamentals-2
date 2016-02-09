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

Shape::Shape(){
}

float Shape::area(){
	return 0;
}

float Shape::perimeter(){
	return 0;
}

string Shape::get_type(){
	return "shape";
}

void Shape::print(){
	cout << "???" << endl;
}

float Rectangle::area(){
	return width * height;
}

float Rectangle::perimeter(){
	return 2 * (width + height);
}

Rectangle::Rectangle(float w, float h){
	width = w;
	height = h;
}

string Rectangle::get_type(){
	return "rectangle";
}

void Rectangle::print(){
	cout << "+" << flush;
	for(int i =0; i< width; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;
	for(int i =0; i< height; i++){
		cout << "|" << flush;
		for(int j =0; j < width ; j++){
			cout << " " << flush;
		}
		cout << "|" << endl;

	}

	cout << "+" << flush;
	for(int i =0; i< width; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;
}

float Triangle::area(){
	return  base * height /2;
}

float Triangle::perimeter(){
	return base+ height+ sqrt(base*base+height*height);
}

Triangle::Triangle(float b, float h){
	base = b;
	height = h;
}

string Triangle::get_type(){
	return "triangle";
}

void Triangle::print(){

	cout << "+" << endl;

	for (int i =0; i< height; i++){
		cout << "|" << flush;

		for(int j= 0; j < i; j++){
			cout << " " << flush;
		}
		cout << "\\" << endl;
		
	}

	cout << "+" << flush;

	for (int i =0; i < base; i++){
		cout << "-" << flush;
	}
	cout  << "+" << endl;

}

float Square::area(){
	return side * side;
}

float Square::perimeter(){
	return 4 * side;
}

Square::Square(float s){
	side = s;
}

string Square::get_type(){
	return "square";
}

void Square::print(){

	cout << "+" << flush;
	for(int i =0; i< side; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;
	for(int i =0; i< side; i++){
		cout << "|" << flush;
		for(int j =0; j < side ; j++){
			cout << " " << flush;
		}
		cout << "|" << endl;

	}

	cout << "+" << flush;
	for(int i =0; i< side; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;

}




int main(){
    Shape s1;
    cout << "Shape type          : " << flush;
    cout << (s1.get_type() == "shape" ? "good" : "FAIL") << endl;
    cout << "Shape area          : " << flush;
    cout << "0 = " << s1.area() << endl;
    cout << "Shape perim         : " << flush;
    cout << "0 = " << s1.perimeter() << endl;
 
    Rectangle r1(3,4);
    cout << "Rectangle type      : " << flush;
    cout << (r1.get_type() == "rectangle" ? "good" : "FAIL") << endl;
    cout << "Rectangle area      : " << flush;
    cout << "12 = " << r1.area() << endl;
    cout << "Rectangle perim     : " << flush;
    cout << "14 = " << r1.perimeter() << endl;

	
    Triangle t1(3,4);
    cout << "Triangle type       : " << flush;
    cout << (t1.get_type() == "triangle" ? "good" : "FAIL") << endl;
    cout << "Triangle area       : " << flush;
    cout << "6 = " << t1.area() << endl;
    cout << "Triangle perim      : " << flush;
    cout << "12 = " << t1.perimeter() << endl;

    Square sq1(5);
    cout << "Square type         : " << flush;
    cout << (sq1.get_type() == "square" ? "good" : "FAIL") << endl;
    cout << "Square area         : " << flush;
    cout << "25 = " << sq1.area() << endl;
    cout << "Square perim        : " << flush;
    cout << "20 = " << sq1.perimeter() << endl;

    cout << "\nSHAPE POINTER STUFF!!!\n" << endl;

    Shape * s = new Shape();    
    cout << "Shape type          : " << flush;
    cout << (s->get_type() == "shape" ? "good" : "FAIL") << endl;
    cout << "Shape area          : " << flush;
    cout << "0 = " << s->area() << endl;
    cout << "Shape perim         : " << flush;
    cout << "0 = " << s->perimeter() << endl;
    delete s;

    s = new Rectangle(3,4);
    cout << "Rectangle type      : " << flush;
    cout << (s->get_type() == "rectangle" ? "good" : "FAIL") << endl;
    cout << "Rectangle area      : " << flush;
    cout << "12 = " << s->area() << endl;
    cout << "Rectangle perim     : " << flush;
    cout << "14 = " << s->perimeter() << endl;
    delete s;

    s = new Triangle(3,4);
    cout << "Triangle type       : " << flush;
    cout << (s->get_type() == "triangle" ? "good" : "FAIL") << endl;
    cout << "Triangle area       : " << flush;
    cout << "6 = " << s->area() << endl;
    cout << "Triangle perim      : " << flush;
    cout << "12 = " << s->perimeter() << endl;
    delete s;

    s = new Square(5);
    cout << "Square type         : " << flush;
    cout << (s->get_type() == "square" ? "good" : "FAIL") << endl;
    cout << "Square area         : " << flush;
    cout << "25 = " << s->area() << endl;
    cout << "Square perim        : " << flush;
    cout << "20 = " << s->perimeter() << endl;
    delete s;

    cout << "\nPRINT SHAPE STUFF!!!\n" << endl;
    cout << "Square: " << endl;
    sq1.print();
    cout << "\nRectangle: " << endl;
    r1.print();
    cout << "\nTriangle: " << endl;
    t1.print();
    cout << "\nShape: " << endl;
    s1.print();

}


