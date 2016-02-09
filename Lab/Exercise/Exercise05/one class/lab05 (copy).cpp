#include <iostream>
#include <string>
using namespace std;

const int GROUP_SIZE = 10;

class Group{
private:
// These globals keep track of the state of our group
string names[GROUP_SIZE];
int names_size;
int ages[GROUP_SIZE];
int ages_size;

public:
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

void menu();
int get_input();


int main(){
	Group g;
    int choice = -1;
    string temp_name;
    int temp_age;
    while(choice){
        cout << endl;
        menu();
        choice = get_input();
        cout << endl;
        if(choice == 1){
            g.get_insert(temp_name, temp_age);
            int success = g.insert_person(temp_name, temp_age);
            if(success)
                cout << temp_name << " inserted successfully" << endl;
            else
                cout << "Error inserting " << temp_name << endl;
        }
        else if(choice == 2){
            g.get_delete(temp_name);
            int success = g.delete_person(temp_name);
            if(success)
                cout << temp_name << " deleted successfully" << endl;
            else
                cout << "Error deleting " << temp_name << endl;
        }
        else if(choice == 3){
            g.print_people();
        }
    }
}

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





