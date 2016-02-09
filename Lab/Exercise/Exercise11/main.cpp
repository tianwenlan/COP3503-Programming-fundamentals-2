#include <iostream>
#include "defs.h"
using namespace std;

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