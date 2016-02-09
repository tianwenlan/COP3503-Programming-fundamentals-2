#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int echo_1(string inFileName);
int echo_2(ifstream & inFile);
void echo_3(string inFileName, int & readSuccess);
void echo_4(ifstream & inFile, int & readSuccess);
int echo_5(string inFileName, string outFileName);


int main(){
  ifstream input;
  ofstream output;
  ifstream a;
  ifstream & inFile = a;

  string inFileName;
  string outFileName;
  string tempString;
  int num;
  int readSuccess;

  
  while (1){
	  cout << "Please enter the command number (1-5) for test > " << flush;
	  cin >> num;
	  switch (num){
	  case 1:
		cout << "Please enter the file name > " << flush;
		cin >> inFileName;
		echo_1(inFileName);
		break;
	  case 2:
		echo_2(inFile);
		break;
	  case 3:
		cout << "Please enter the file name > " << flush;
		cin >> inFileName;

		echo_3(inFileName, readSuccess);
		break;
	  case 4:
		echo_4(inFile, readSuccess);
	    break;
	  case 5:
	    cout << "Please enter the input file name > " << flush;
    	cin >> inFileName;

	    cout << "Please enter the output file name > " << flush;
	    cin >> outFileName;

	    echo_5(inFileName, outFileName);
	  }
  }
  return 0;
}


int echo_1(string inFileName){
  ifstream input;
  string inFilename;
  string tempString;

  input.open(inFileName.c_str());
  if (input.fail()) return 0;

  while (!input.eof()){
    input >> tempString;
	cout << tempString << endl;

   }
  return 1;
}



int echo_2(ifstream & inFile){
  string tempString;
  if (inFile.fail()) return 0;
  while (!inFile.eof()){
    inFile >> tempString;
	cout << tempString << flush;
  }
  return 1;
}


void echo_3(string inFileName, int & readSuccess){
	ifstream input;
	string tempString;

    input.open(inFileName.c_str());
    if (input.fail()) readSuccess = 0;
	
    while (!input.eof()){
	input >> tempString;
	cout << tempString << endl;
	}
	readSuccess = 1;
}


void echo_4(ifstream & inFile, int & readSuccess){
	  string tempString;
      if (inFile.fail()) readSuccess = 0;
      while (!inFile.eof()){
      inFile >> tempString;
	  cout << tempString << endl;
	  readSuccess = 1;
      }
}


int echo_5(string inFileName, string outFileName){
	ifstream input;
	ofstream output;
	string tempString;

	input.open(inFileName.c_str());
	if (input.fail()){
		cout << "File " << inFileName << " cannot be opened" << endl;
	} else
        output.open(outFileName.c_str());
	while (!input.eof()){
		input >> tempString;
        output << tempString << endl;
	}
	return 0;
}




