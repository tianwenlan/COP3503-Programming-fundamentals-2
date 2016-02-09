#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include "strstuff.h"
using namespace std;

//This function computes the factorial of a number
int factorial(int n){
    int fact = 0;
    while(n >= 0){
        fact *= n;
        --n;
    }
    return fact;
}

//This function is supposed to initialize an array of a given
//size with random values in each of its slots.
void init_test_array(int * test, int size){
    for(int i=0; i<size; i++)
        test[i] = rand()%100;
    return;
}

//This function is supposed to sum up the elements of an
//array of a given size
int sum_test_array(int * test, int size){
    int sum = 0;
    int a[test[0]];
    for(int i; i<size; i++)
        sum += test[i];
    return sum;
}

int main(){
    srand(time(0));

    //Creating a random array to get the sum of 10 random numbers...
    int test_array[10];
    
    int array_size;

    init_test_array(test_array, array_size);
    int sum = sum_test_array(test_array, array_size);
    cout << "Sum of random numbers is: " << sum << endl;


    //This next section does some useful factorial stuff.
    for(int i=1;i<10;i++)
        cout << i << "/fact(" << i << ") is " << (i/factorial(i)) << endl;

    /*
    //This section does a bit of manipulation with cstrings
    Str * str = new Str("The magic words are squeamish ossifrage");

    str->echo();
    cout << "The string is " << str->length() << " characters long" << endl;

    delete str;
    */
}