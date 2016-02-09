#include <iostream>
using namespace std;

// a very basic C++ object
class Person
{
    public: // constructor “prototype”
		Person(string name, int age);	
		string getName();
	    int getAge();
		void setName(string);
		void setAge(int);
		void haveABirthday();

		string name;
		int age;

};

    Person::Person(string name, int age)
	{
		this->name = name;
		this->age = age;
    }

	string Person::getName(){
		return this -> name;
	}
	int Person::getAge(){
		return this -> age;
	}
 /*   
	void Person::setName(string name){
		this->name = name;
	}
	void Person::setAge(int age){
		this-> age = age;
	}

	void Person::haveABirthday(){
		this->age++;
	}
*/

int main() { 
	Person *p = new Person("Jason", 20);
	(*p).age=19;

	cout << p->name << endl;
	delete p;
	
  }

