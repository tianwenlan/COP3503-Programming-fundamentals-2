#ifndef STR_STUFF_H
#define STR_STUFF_H
#include <cstring>
#include <iostream>
using namespace std;

class Str{
    char * buf;

    public:

    Str();
    Str(string);
    ~Str();
    void echo();
    int length();
};

#endif