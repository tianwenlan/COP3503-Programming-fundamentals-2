#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "COP3503su14_Proj2_WenlanT_multiSet.h"

using namespace std;

	MultiSet::MultiSet():size(0){
	}

//case 1: empty the current multiset, and fill it with the multiset from a file
	int MultiSet::inputFile(string inFileName){
		ifstream inStream;
		Object o;
		string tempName;
		int tempCount;
		string line;

		multiSet.clear();
		size = 0;

		inStream.open(inFileName.c_str());

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}

		// get next line from console
		while(getline(inStream,line)){
			// convert input line into a stream
			istringstream record(line);
			// read from stream a string and an int

			record >> tempName;
			record >> tempCount;

			// if the line has no printable chars
			// or if the second string is not a number
			// // the input line is malformed
			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{

			o.setName(tempName);
			o.setCount(tempCount);

			multiSet.push_back(o);
			size ++;
			}

			// now see if there is more stuff in the line
			if (!record.eof()){
				// try to read it
				record >> tempName;
				if (!record.fail())
				// if read a string, then bad line
				cerr << "line malformed: " << line << endl;
				// if fail to read a string,
				// then just white space left,
				// no big deal
				}

				// reset tempName to empty so we don't print junk
				tempName = "";
			}

		inStream.close();
		if (!silent){
			cout << "New Set Loaded" << endl;
		}
		return 1;	
	}


//case 6:reset current set to the empty set
	int MultiSet::reset(){
		multiSet.clear();
		if (!silent){
			cout << "Reset completed" << endl;
		}
		size = 0;
		return 1;
	}


//case 7: open and write the current set to a file   
	int MultiSet::printToFile(){
		string outFileName;
		ofstream output;

		cin >> outFileName;
		output.open(outFileName.c_str()); 
		if (output.fail()){
			if (!silent){
				cerr << "File " << outFileName << " cannot be opened" << endl;
			}
			return 0;
		}

		for (int i = 0; i < size; i++)
		{
			output << multiSet.at(i).getName() << " " << multiSet.at(i).getCount() << endl;
		} 
			if (!silent){
				cout << "Save to " << outFileName << " completed" << endl;
			}
		return 1;
	} 


  
//case 8: print current set to the console
	void MultiSet::print(){
		cout << "Current multiset:" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << multiSet.at(i).getName() << " " << multiSet.at(i).getCount() << endl;
		} 
	}


  
//case 2: open and union a set from a file with the current set  
	int MultiSet::unionSets(){
		Object o;
		string inFileName;
		ifstream inStream;
		string tempName;
		int tempCount;
		string line;

		cin >> inFileName;

		inStream.open(inFileName.c_str()); 

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}

		while(getline(inStream,line)){
			istringstream record(line);
			record >> tempName;			
			record >> tempCount;

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{
				o.setName(tempName);
				o.setCount(tempCount);
			}

			if (!record.eof()){
				record >> tempName;
				if (!record.fail())
				cerr << "line malformed: " << line << endl;
			}

			bool found = false;

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					multiSet[i].setCount(multiSet[i].getCount() + o.getCount());
					found = true;
				}
			}

			if (!found){
				multiSet.push_back(o);
				size ++;
			}

				// reset tempName to empty so we don't print junk
			tempName = "";
		}

		inStream.close();

		if (!silent){
			cout << inFileName << " union completed" << endl;
		}
		return 1;
	}


//case 3: open and subtract set from a file from the current set
  int MultiSet::subtractSets(){
		Object o;
		string inFileName;
		ifstream inStream;
		string tempName;
		int tempCount;
		string line;

		cin >> inFileName;

		inStream.open(inFileName.c_str()); 

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}

		while(getline(inStream,line)){
			istringstream record(line);
			record >> tempName;
			record >> tempCount;

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{
				o.setName(tempName);
				o.setCount(tempCount);
			}

			if (!record.eof()){
				record >> tempName;
				if (!record.fail())
				cerr << "line malformed: " << line << endl;
			}

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					if(!silent)
						multiSet[i].setCount(multiSet[i].getCount() - o.getCount());
						if (multiSet[i].getCount() >0){
						}else{
							multiSet.erase(multiSet.begin()+i);
							size --;
						}
				}
			}

				// reset tempName to empty so we don't print junk
			tempName = "";
		}		

		inStream.close();

		if (!silent){
			cout << inFileName << " subtraction completed" << endl;
		}
		return 1;	  
	}


//case 4: open and find the difference between a set from a file and the current set
	int MultiSet::differenceSets(){
		Object o;
		string inFileName;
		ifstream inStream;
		string tempName;
		int tempCount;
		string line;

		cin.clear();
		cin.ignore();

		cin >> inFileName;

		inStream.open(inFileName.c_str());        
		
		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}

		while(getline(inStream,line)){
			istringstream record(line);
			record >> tempName;
			record >> tempCount;

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{
				o.setName(tempName);
				o.setCount(tempCount);
			}

			bool found = false;

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					multiSet[i].setCount(abs (multiSet[i].getCount() - o.getCount()));
					if(multiSet[i].getCount() == 0){
						multiSet.erase(multiSet.begin()+i);
						size--;
					}
				found = true;
				}
			}

			if (!found){
				multiSet.push_back(o);
				size ++;
			}

			if (!record.eof()){
				record >> tempName;
				if (!record.fail())
					cerr << "line malformed: " << line << endl;
			}

				// reset tempName to empty so we don't print junk
				tempName = "";
		}		

		inStream.close();

		if (!silent){
			cout << inFileName << " difference completed" << endl;
		}
		return 1;
	} 


//case 5: open and find the intersection between a set from a file and the current set  
	int MultiSet::intersectSets(){
		Object o;
		string inFileName;
		ifstream inStream;
		string tempName;
		int tempCount;
		string line;
		vector<Object> myMultiSet;
		int mySize=0;

		cin >> inFileName;

		inStream.open(inFileName.c_str()); 

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}
		
		while(getline(inStream,line)){
			istringstream record(line);
			record >> tempName;
			record >> tempCount;

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{
				o.setName(tempName);
				o.setCount(tempCount);
			}

			if (!record.eof()){
				record >> tempName;
				if (!record.fail())
				cerr << "line malformed: " << line << endl;
			}

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					myMultiSet.push_back(multiSet[i]);
				    mySize++;
				}
			}

			for (int i = 0; i < mySize; i++){
				if (myMultiSet[i].getName() == o.getName()){
					if(myMultiSet[i].getCount() > o.getCount()){
						myMultiSet[i].setCount(o.getCount());				
					}
				}
			}
				// reset tempName to empty so we don't print junk	
			tempName = "";			
		}	

		multiSet = myMultiSet;
		size = mySize;
		
		inStream.close();

		if (!silent){
			cout << inFileName << " intersetction completed" << endl;
		}
		return 1; 
	}
 

//case 9: test if a given item is in the current multiset
	int MultiSet::findItem(string itemName){

		string input;
		cin.clear();
		cin.ignore();

		while(getline(cin,input)){
			istringstream record(input);

			record >> itemName;

			if (itemName == "STOP") break;

			if (!record.eof()){
				record >> itemName;
				if (!record.fail())
				cerr << "Invalid input!" << endl;
				cout << "please reenter the <item name> (Enter STOP to quit):" << endl;
				continue;
			}

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == itemName){
					if(!silent){
						cout << "Item " << itemName << " found with count " << multiSet[i].getCount() << endl;
					}
				return i;
				}
			}
	   
			if(!silent){
				cout << "Item " << itemName << " not in multiSet" << endl;
			}
			return -1;

			itemName = "";
		}
	return 1;
 }


//case 10: add an item to the current set if it is not already in it
	int MultiSet::insertItem(string itemName, int count){
		Object o;
		
		string input;
		cin.clear();
		cin.ignore();

		while(getline(cin,input)){
			istringstream record(input);

			record >> itemName;
			record >> count;

			if (itemName == "STOP") break;

			if (record.fail()) {
				if (input.empty()){
					if (!silent){
						cerr << "No input!" << endl;
						cout << "Please enter the <item name> and <count> to be inserted (Enter STOP to quit):" << endl;
					}
				} 
				
				if (input==itemName){
					if(!silent){
					cerr << "Invalid input!" << endl;
					cerr << "<" << itemName << ">" <<"'s <count> is missing" << endl;
					cout << "Please reenter your < item name> and <count>:" << endl;
					}
				}else {				
					if(!silent){
					cerr << "[" << input << "] is not in correct format on user input" << endl;
					cout << "Please make sure the correct format < item name> <count> (Enter STOP to quit):" << endl;
					}				
				}	
				continue;
			}
		
				bool found = false;
				for (int i = 0; i < size; i++){
					if (multiSet[i].getName() == itemName){
						multiSet[i].setCount(multiSet[i].getCount() + count);
						if(!silent){
							cout << "Item " << itemName << " inserted with count " << multiSet[i].getCount() << endl;
						}
					found = true;
					}
				}

				if (!found){
					o.setName(itemName);
					o.setCount(count);
					multiSet.push_back(o);
					if (!silent){
						cout << "Item " << itemName << " inserted with count " << count << endl;
					}
					size ++;
				}
				return 1;
			
				itemName = "";
		}
		return 1;
	}


//case 11: remove and item from the current set if it is in it
	int MultiSet::deleteItem(string itemName){

		string input;
		cin.clear();
		cin.ignore();

		while(getline(cin,input)){
			istringstream record(input);

			record >> itemName;

			if (itemName == "STOP") break;

			if (!record.eof()){
				record >> itemName;
				if (!record.fail())
				cerr << "Invalid input!" << endl;
				cout << "please reenter the <item name> (Enter STOP to quit):" << endl;
				continue;
			}


			bool found = false;

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == itemName){
					multiSet.erase(multiSet.begin()+i);
					if(!silent){
						cout << "Item " << itemName << " deleted " << endl;
					}
				found = true;
				size --;
				}
			}

			if (!found)	   
				if(!silent){
					cout << "Item " << itemName << " not in set" << endl;
				}
			return -1;

			itemName = "";
		}
		return 1;
	}



//case 12:   
	int MultiSet::reduceItem(string itemName, int count){

		string input;
		cin.clear();
		cin.ignore();

		while(getline(cin,input)){
			istringstream record(input);

			record >> itemName;
			record >> count;

			if (itemName == "STOP") break;

			if (record.fail()) {
				if (input.empty()){
					if (!silent){
						cerr << "No input!" << endl;
						cout << "Please enter the <item name> and <count> to be inserted (Enter STOP to quit):" << endl;
					}
				} 
				
				if (input==itemName){
					if(!silent){
					cerr << "Invalid input!" << endl;
					cerr << "<" << itemName << ">" <<"'s <count> is missing!!" << endl;
					cout << "Please reenter your < item name> and <count> (Enter STOP to quit):" << endl;
					}
				}else {				
					if(!silent){
					cerr << "[" << input << "] is not in correct format on user input" << endl;
					cout << "Please make sure the correct format < item name> <count> (Enter STOP to quit):" << endl;
					}				
				}	
				continue;
			}

			bool found = false;
			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == itemName){
					multiSet[i].setCount(multiSet[i].getCount() - count);
					found = true;
					if (multiSet[i].getCount() >0){
						if(!silent){
							cout << "Item " << itemName << " count reduced to " << multiSet[i].getCount() << endl;
						}
					}else{
						multiSet.erase(multiSet.begin()+i);
						if(!silent){
							cout << "Item " << itemName << " removed" << endl;
						}
						size --;
					}
				}
			}

			if ( !found){
				if (!silent){
					cout << "Item " << itemName << " not in multiset" << endl;
					cout << "Please reenter your < item name> and <count> (Enter STOP to quit):" << endl;
				}
			}
			
			return 1;
				itemName = "";	
		}
		
		return 1;
	}

//case 17: Max
	int MultiSet::maxSets(){
		Object o;
		string inFileName;
		ifstream inStream;
		string tempName;
		int tempCount;
		string line;

		cin >> inFileName;

		inStream.open(inFileName.c_str());        

		if(inStream.fail()) {
			cerr << "Unable to open file: " << inFileName << endl;
		return 0;
		}

		while(getline(inStream,line)){
			istringstream record(line);
			record >> tempName;
			record >> tempCount;

			if (record.fail()) {
				if (line.empty()){
					if (!silent){
						cerr << "This line is empty" << endl;
					}
				}

				if (line==tempName){
					if(!silent){
					cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
					}
				}else if (line!=""){
					if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
					cout << "Please make sure the correct format: < item name> <count> per line" << endl;
					}
				}
				continue;
			}

			if(tempCount <= 0){
				if(!silent){
				cerr << "Invalid count number! <Count> should be larger than 0" << endl;
				}
			}else{
				o.setName(tempName);
				o.setCount(tempCount);
			}

			if (!record.eof()){
				record >> tempName;
				if (!record.fail())
				cerr << "line malformed: " << line << endl;
			}

			bool found = false;

			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					if(!silent)
						if (multiSet[i].getCount() >= o.getCount()){
						multiSet[i].setCount(multiSet[i].getCount());
						}
						if(multiSet[i].getCount() < o.getCount()){
						multiSet[i].setCount(o.getCount());
						}
					found = true;
				}
			}

			if (!found){
				multiSet.push_back(o);
				size ++;
			}
			tempName = "";
		}		
		
		inStream.close();

		if (!silent){
			cout << "Max completed" << endl;
		}
		return 1;
	}
