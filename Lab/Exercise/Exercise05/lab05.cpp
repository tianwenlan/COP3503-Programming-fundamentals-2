#include <iostream>
#include <string>
#include "lab05.h"
using namespace std;


void menu(){
    cout << "1. Add person" << endl;
    cout << "2. Delete Person" << endl;
    cout << "3. Print list" << endl;
    cout << "0. Exit" << endl;
    cout << endl << "> " << flush;
}

int get_input(){
    int input;
    cin >> input;
    return input;
}

int Person::getAge(){
    return agi;
}

void Person::setAge(int a){
    age=int a;
}


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
    for(int i=0;i<names_size; i++){
        if(names[i] == name){
            index = i;
            i = names_size;
        }
    }
    return index;
}

int Group::insert_person(string name, int age){
    // If our group is full, we cannot add anymore
    if(names_size == GROUP_SIZE) return 0;

    // Find where we need to insert the person
    int index = names_size;
    for(int i=0;i<names_size; i++){
        if(names[i].compare(name) > 0){
            index = i;
            i = names_size;
        }
    }

    // Move everyone else down one space to make room
    for(int i=names_size;i>index;i--){
        names[i] = names[i-1];
        ages[i] = ages[i-1];
    }

    // Insert the person
    names[index] = name;
    ages[index] = age;
    names_size++;
    return 1;
}

int Group::delete_person(string name){
    // Check if the person is in the list
    int index = find_index(name);
    if(index == -1) return 0;

    // Move everyone lower than the one we are deleting 
    for(int i=index;i<names_size;i++){
        names[i] = names[i+1];
        ages[i] = ages[i+1];
    }

    names_size--;
    ages_size--;

    return 1;
}

void Group::print_people(){
    for(int i=0;i<names_size;i++){
        cout << names[i] << ", " << ages[i] << endl;
    }
}



