#include <iostream>
#include <string>
#include <cmath>
#include "defs.h"

using namespace std;

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
	for(int i =0; i< 2*side; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;
	for(int i =0; i< side; i++){
		cout << "|" << flush;
		for(int j =0; j < 2*side ; j++){
			cout << " " << flush;
		}
		cout << "|" << endl;

	}

	cout << "+" << flush;
	for(int i =0; i< 2*side; i++){
		cout << "-" << flush;
	}
	cout << "+" << endl;

}


