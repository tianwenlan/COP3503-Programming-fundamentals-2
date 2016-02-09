#include <iostream>
#include <string>
#include "group.h"
using namespace std;

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

