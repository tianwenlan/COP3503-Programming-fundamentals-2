#include "strstuff.h"
using namespace std;

//Default constructor
Str::Str(){
    buf = new char[50];
    strcpy(buf, "The magic words are squeamish ossifrage");
}

//Constructor that takes in a string 
Str::Str(string str){
    buf = new char[str.size() + 1];
    strcpy(buf, str.c_str());
}

//Destructor, we must write one because we used new in our constructor
Str::~Str(){
    cout << "Deconstructed" << endl;
    delete [] buf;
}

//Just prints out the string character by character
void Str::echo(){
    char c = '~';
    int i=0;
    while(buf[i++] != '\0') {
        buf[i] = c;
        cout << c;
    }
    cout << endl;
    return;
}

//Returns the length of a string
int Str::length(){
    int i=0;
    while(buf[i++] != '\0')
        ;
    return i;
}