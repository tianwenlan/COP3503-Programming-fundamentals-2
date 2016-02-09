#include <iostream>
#include <string>
#include "group.h"
using namespace std;


int Person::getAge(){
    return this -> age;
}

string Person::getName(){
	return this -> name;
}

void Person::setAge(int a){
    this->age=a;
}

void Person::setName(string n){
	this->name=n;
}

Group::Group() : size(0) {}

void Group::get_insert(string & name, int & age){
    cin >> name;
	cin >> age;
}


void Group::get_delete(string & name){
    cin >> name;
}

/////////////////////////////////////////////////////////////////
// Hint Hint, This comment separates logical chunks of code... //
/////////////////////////////////////////////////////////////////

int Group::find_index(string name){
    int index = -1;
    for(int i=0;i<size; i++){
        if(people[i].getName() == name){
            index = i;
            i = size;
        }
    }
    return index;
}


int Group::insert_person(string name, int age){


    // If our group is full, we cannot add anymore
    if(size == GROUP_SIZE) return 0;

    // Find where we need to insert the person
    int index = size;
    for(int i=0;i<size; i++){
        if(people[i].getName().compare(name) > 0){
            index = i;
            i = size;
        }
    }


    // Move everyone else down one space to make room
    for(int i=size;i>index;i--){
		people[i]=people[i-1];
    }
 
    // Insert the person
    people[index].setName(name);
    people[index].setAge(age);
    size++;
    return 1;
}

int Group::delete_person(string name){
    // Check if the person is in the list
    int index = find_index(name);
    if(index == -1) return 0;

    // Move everyone lower than the one we are deleting 
    for(int i=index;i<size;i++){
		people[i]=people[i+1];
    }

    size--;
    
    return 1;
}

void Group::print_people(){
    for(int i=0;i<size;i++){
        cout << people[i].getName() << ", " << people[i].getAge() << endl;
    }
}





