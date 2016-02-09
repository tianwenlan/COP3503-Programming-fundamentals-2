#include <string>
#include "COP3503su14_Proj2_WenlanT_object.h"

using namespace std;

	string Object::getName(){
		return this -> name;
	}

	int Object::getCount(){
		return this -> count;
	}

	void Object::setName(string name){
		this->name=name;
	}

	void Object::setCount(int count){
		this->count=count;
	}

