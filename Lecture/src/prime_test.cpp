/* prime_test.cpp
 * by R. Newman 5/28/14
 * Simple program that shows use of functions
 *   tests for primality
 */

#include <iostream>
#include <iomanip>
using namespace std;

bool isPrime(int candidate){	// naive prime test
  for (int i = 2; i <= candidate/2; i++) {
    if (candidate % i == 0) return false;
  }
  return true;
}

int main() {
  int i = 2;
  cout << "Test for primality" << endl;
  cout << "Enter 1 to quit" << endl;
  while (i > 1) {
    cout << "Number to test: " << flush;
    cin >> i;
    if (i != 1) cout << i;
    if (i < 1) 
      cout << " is not valid" << endl;
    else if (i > 1) {
      if (isPrime(i)) 
        cout << " is prime" << endl;
      else
        cout << " is not prime" << endl;
    }
  }
  cout << "Bye" << endl;
  return 0;

}
