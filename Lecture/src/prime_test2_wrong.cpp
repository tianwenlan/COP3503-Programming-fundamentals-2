/* prime_test2_wrong.cpp
 * by R. Newman 5/28/14
 * Simple program that shows use of functions
 *   tests for primality
 * Also shows display modes and cmdline args
 * Has nested if errors
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

const string HELP = "prime_test2 [-s] [-h] \n"
    "\tCommand line parameters:\n"
    "\t\t-s: silent mode - no prompts, 0/1 output\n"
    "\t\t-h: print this help info first\n"
    "\tInput:\n"
    "\t\t1 to quit\n"
    "\t\tnumbers greater than 1 to output primality\n"
    "\t\tnumbers <1 are invalid\n"
    "\tOutput:\n"
    "\t\tOn valid input, states if input is prime or not prime\n"
    "\t\tIn silent mode, output is 1 if prime, 0 if not prime\n";

const string SOPT = "-s";
const string HOPT = "-h";

int main(int argc, char *argv[]) {
  bool silent = false;
  const bool debug = true;

  if (debug) {
    cout << argc << endl;
    for (int i = 0; i < argc; ++i) {
      cout << argv[i] << endl;
    }
  }

  for (int n = 1; n < argc; n++) { 	// parse cmdline args
    if (argv[n] == SOPT) silent = true;
    else if (argv[n] == HOPT) cout << HELP << endl;
    else cerr << "Invalid commandline argument: " << argv[n] << endl;
  }

  int i = 2;
  if (!silent) cout << "Test for primality" << endl;
  if (!silent) cout << "Enter 1 to quit" << endl;
  while (i > 1) {
    if (!silent) cout << "Number to test: " << flush;
    cin >> i;
    if (!silent & (i != 1)) cout << i;
    if (i < 1) 
      if (!silent) cout << " is not valid" << endl;
    else if (i > 1) {
      if (isPrime(i)) 
        if (!silent) cout << " is prime" << endl;
        else cout << "1" << endl;
      else
        if (!silent) cout << " is not prime" << endl;
        else cout << "0" << endl;
    }
  }
  if (!silent) cout << "Bye" << endl;
  return 0;

}
