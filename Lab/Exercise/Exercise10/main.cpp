#include "DynamicArray.h"
#include <iostream>
#include <string>
using namespace std;

void pop_da(DynamicArray & da, string * str, int n){
    for(int i=0; i<n; i++)
        da.insert(str[i]);
    cout << endl;
}

void do_some_testing(string * first, int n1){
    static int run = 1;

    DynamicArray da1;

    cout << "-----------------------------------" << endl;
    cout << "              TEST " << run++ << endl;
    cout << "-----------------------------------" << endl;
    pop_da(da1, first, n1);

    cout << "Inserting done" << endl;

    cout << "initial size:                 " << flush;
    cout << (n1 == da1.size() ? "Good" : "FAIL") << endl;
    cout << "index of second to last el:   " << flush;
    cout << (n1-2 == da1.index_of(first[n1-2]) ? "Good" : "FAIL") << endl;
    cout << "item at 0:                    " << flush;
    cout << (first[0] == da1.item_at(0) ? "Good" : "FAIL") << endl;
    cout << "item at end:                  " << flush;
    cout << (first[n1-1] == da1.item_at(n1-1) ? "Good" : "FAIL") << endl;
    cout << "remove:                       " << flush;
    cout << (first[n1-1] == da1.remove() ? "Good" : "FAIL") << endl;
    cout << "remove index 1:               " << flush;
    cout << (first[1] == da1.remove(1) ? "Good" : "FAIL") << endl;
    cout << "new item at 1:                " << flush;
    cout << (first[2] == da1.item_at(1) ? "Good" : "FAIL") << endl;
    cout << "removing new 1, tesing new 2: " << flush;
    da1.remove(first[2]);
    cout << (first[4] == da1.item_at(2) ? "Good" : "FAIL") << endl;
    cout << "final size:                   " << flush;
    cout << (n1-3 == da1.size() ? "Good" : "FAIL") << endl;
    cout << "Inserting pickle:             " << flush;
    da1.insert("pickle");
    cout << (n1-3 == da1.index_of("pickle") ? "Good" : "FAIL") << endl;
    cout << "Index of invalid:             " << flush;
    cout << (-1 == da1.index_of("sdjdjkskdskj") ? "Good" : "FAIL") << endl;
    cout << "Invalid index big:            " << flush;
    cout << ("" == da1.item_at(10000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index big remove:     " << flush;
    cout << ("" == da1.remove(10000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index small:          " << flush;
    cout << ("" == da1.item_at(-1000) ? "Good" : "FAIL") << endl;
    cout << "Invalid index small remove:   " << flush;
    cout << ("" == da1.remove(-1) ? "Good" : "FAIL") << endl;
    cout << "Testing capacity:             " << da1.capacity() << endl; 

}

int main(){
    string test[] = {"The","Magic","Words","Are","Squeamish","Ossifrage.","You","better","believe","it", "useless", "words"};

    string letters[] = {"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

    string numbers[] = {"0","1","2","3","4","5","6","7","8","9"};

    string symbols[] = {"!","@","#","$","?","^","&","*","(",")" };
    
    string * big_test = new string[1000];
    for(int i=0;i<1000;i++){
        big_test[i] = to_string(i);
    }

    do_some_testing(test, 12);
    cout << endl;
    do_some_testing(letters, 26);
    cout << endl;
    do_some_testing(big_test, 1000);

    DynamicArray na;
    DynamicArray la;
    DynamicArray sa;
    pop_da(na, numbers, 10);
    pop_da(la, letters, 26);
    pop_da(sa, symbols, 10);


    cout << "Numbers: " << na << endl;
    cout << "Letters: " << la << endl;
    cout << "Symbols: " << sa << endl;

    cout << "Numbers + letters: " << (na + la) << endl;
    cout << "Numbers + letters + symbols: " << (na + la + sa) << endl;

    DynamicArray combo;
    combo = na;

    cout << "combo n: " << combo << endl;
    combo = na + combo;
    cout << "combo n + combo: " << combo << endl;

    for(int i=0; i<10; i++){
        cout << combo[i] << " " << flush;
    }
    cout << endl;
}
