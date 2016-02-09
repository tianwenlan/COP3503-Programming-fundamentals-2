#include <iostream>
#include <string>
using namespace std;

const int GROUP_SIZE = 10;

class Person{
	public:
    string name;
    int age;
    
    public:
	Person(string,int);
	Person();
    int getAge();
    string getName();
	void setAge(int);
	void setName(string);
};

class Group{
	private:
	Person people[GROUP_SIZE];
	int size;

	public:
	// This function inserts a person with the given name and age
	int insert_person(string, int);
	
	// This function deletes a person with the given age
    //	int delete_person(string);

	// This function prints out the people in our group
	//	void print_people();

	// This function returns the index of the given person. -1 on fail.
	// This is an auxillary function 
	//	int find_index(string);

//    void get_insert(Person &);
	//	void get_delete(string &);

};

int get_input();
void menu();

int main(){
	Group g;
	Person p;
    int choice = -1;
    string temp_name;
    int temp_age;
    while(choice){
        cout << endl;
        menu();
        choice = get_input();
        cout << endl;
        if(choice == 1){
 //           p.setName(temp_name);
 //           p.setAge(temp_age);
            int success = g.insert_person(temp_name,temp_age);
            if(success)
                cout << temp_name << " inserted successfully" << endl;
            else
                cout << "Error inserting " << temp_name << endl;
        }
/*        else if(choice == 2){
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
        */
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

Person::Person(){
}

Person::Person (string name,int age){
		this->name = name;
		this->age = age;
	}


int Person::getAge(){
    return this -> age;
}

string Person::getName(){
	return this -> name;
}

void Person::setAge(int a){
	cin >> a;
    this->age=a;
}

void Person::setName(string n){
	cin >> n;
	this->name=n;
}

/*
void Group::get_insert(Person & p){
	int i;
	people[i].name=myPeople->getName();
	people[i].age=myPeople->getAge();
	size++;
	}



void Group::get_delete(string & name){
    cin >> name;
}
*/

/////////////////////////////////////////////////////////////////
// Hint Hint, This comment separates logical chunks of code... //
/////////////////////////////////////////////////////////////////
/*
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
*/

int Group::insert_person(string name, int age){
    // If our group is full, we cannot add anymore
    if(size == GROUP_SIZE) return 0;

    // Find where we need to insert the person
    int index = size;
    for(int i=0;i<size; i++){
        if(people[i].name.compare(people->name) > 0){
            index = i;
            i = size;
        }
    }

    // Move everyone else down one space to make room
    for(int i=size;i>index;i--){
        people[i].name = people[i-1].name;
        people[i].age = people[i-1].age;
    }

    // Insert the person
    people[index].name = people->name;
    people[index].age = people->age;
    size++;
    return 1;
}


/*
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

*/



