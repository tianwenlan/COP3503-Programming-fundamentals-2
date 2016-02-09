#ifndef lab05_H
#define lab05_H
#include <string>

using namespace std;

const int GROUP_SIZE = 10;

class Group{
	
private:

Person people[10];
int size;

// These globals keep track of the state of our group
string names[GROUP_SIZE];
int names_size;
int ages[GROUP_SIZE];
int ages_size;


public:

int getAge();
void setAge(int);

// This function inserts a person with the given name and age
int insert_person(string, int);

// This function deletes a person with the given age
int delete_person(string);

// This function prints out the people in our group
void print_people();

// This function returns the index of the given person. -1 on fail.
// This is an auxillary function 
int find_index(string);



void get_insert(string &, int &);
void get_delete(string &);

};

class Person{
string name;
int age;
};

void menu();
int get_input();

#endif
