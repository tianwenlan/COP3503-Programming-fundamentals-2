/* Proj1.cpp
 * Author: Wenlan Tian
 * Date:05-27-2014
 * Design, document, implement, and test test a system
 * for entering, stroing, manipulating, and printing
 * sets of various sorts.
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Set{
	    string setArray[100];
        int length;
        int maxLength;

		ifstream input;
		ofstream output;

		string inFileName;
		string outFileName;
		string currentSet;
		string line;

		
		void inputFile(){
			input.clear();
			cin >> inFileName;
		    input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			}else 
				cout << "New set loaded" << endl;
			input >> currentSet;

		}

		void unionFile(){
			cin >> inFileName;
			currentSet.open();
			input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			}
			if (currentSet.is_open()){
            	while (!input.eof()){
				if (getline(input,line)=getline(currentSet,line))
				   currentSet << getline(input,line);	
				}
			}

			cout << "Union completed";
		
		}

	

		void subtractFile(){
			cin >> inFileName;
		    input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			} 

	     	cout << "Subtraction completed";

		}

		void differenceFile(){
			cin >> inFileName;
		    input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			} 

			cout << "Difference completed";
			cin >> inFileName;
		    input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			} 


		}

		void intersectFile(){
			cin >> inFileName;
		    input.open(inFileName.c_str());
			if (input.fail()){
				cout << "File " << inFileName << " cannot be opened" << endl;
			} 

			cout << "Intersection completed";

		}

		void resetSet(){
			input.clear();
			cout << "Reset completed";
		}
		
		void outputFile(){
            string tempString;
            cin >> outFileName;
            output.open(outFileName.c_str());
			if (output.fail()){
				cout << "File " << outFileName << " cannot be opened" << endl;
			}
			while (!input.eof()){
				input >> tempString;
			}
		    if (VERBOSE) {
				output << tempString << endl;
		        cout << "Save to " << outFileName << " completed" << endl;
		    }

		}

		void printSet(){
		    string tempString;
			while (!input.eof()){
                input >> tempString;
			    cout << tempString << endl;

			}

		}

/*		void findItem(){
			ofstream output;
			string itemName;
			string line;
			cin >> itemName;
			
			while(!output.eof()){
			if (itemName!=getline(output,line)){
				output << itemName;
				cout << "Item " << itemName << " found";
			} else
				cout << "Item " << itemName << " not found";
			}

		}
*/		

/*		void insertItem(){
			ofstream output;
			string itemName;
			string line;
			cin >> itemName;
			
			while(!output.eof()){
			if (itemName!=getline(output,line)){
				output << itemName;
				cout << "Item " << itemName << " inserted";
			} else
				cout << "Item " << itemName << " already in set";
			}

		}
*/		

/*		void deleteItem(){
			ofstream output;
			string itemName;
			string line;
			cin >> itemName;
			
			while(!output.eof()){
			if (itemName!=getline(output,line)){
				output << itemName;
				cout << "Item " << itemName << " deleted";
			} else
				cout << "Item " << itemName << " not in set";
			}

		}
*/		

		

		void verboseOutput(){
			cout << "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;";
            cout << "4 - difference <file>; 5 - intersect <file>; 6 - reset current set";
            cout << "7 - write <file>; 8 - print; 9 - find <item>; 10 - insert <item>;";
            cout << "11 - delete <item>; 12 - verbose; 13 - normal; 14 - silent; 15 - help;";
		}

		void normalOutput(){
		}

		void silentOutput(){
		}

		void help(){
		cout << "=================================================================" << endl;
		cout << "The numbered commands are as follows: " << endl;
		cout << "0. exit" << endl;
		cout << "1. input file <filename>: open and read a list from a file to the current list" << endl;
		cout << "2. union file <filename>: open and union a set from a file with the current set" << endl;
		cout << "3. subtract file <filename>: open and subtract set from a file from the current set" << endl;
		cout << "4. difference file <filename>: open and find the difference between a set from a file and the current set" << endl;
		cout << "5. intersect file <filename>: open and find the intersection between a set from a file and the current set" << endl;
		cout << "6. reset current set to the empty set" << endl;
		cout << "7. output file <filename>: open and write the current set to a file" << endl;
		cout << "8. print current set to the console" << endl;
		cout << "9. find <item name>: test if <item name> is in the current set" << endl;
		cout << "10. insert <item name>: add <item name> to the current set if it is not already in it" << endl;
		cout << "11. delete <item name>: remove <item name> from the current set if it is in it" << endl;
		cout << "12. verbose output" << endl;
		cout << "13. normal output" << endl;
		cout << "14. silent output" << endl;
		cout << "15. help" << endl;
		cout << "=================================================================" << endl;

		}

};			
			

int main () {
    Set set;

	ifstream input;
	ofstream output;

	string inFileName;
	string outFileName;

	char answer;
	int num;

	cout << "Welcome to use my first program!! " << endl;
	cout << "There are 0-15 different numbers with different functions" << endl;
	cout << "Would you like to see a list of the numbers and how they are to be used? y/n" << endl;
    
	cin >> answer;

	if (answer == 'y'){
		set.help();
	}
	else if (answer == 'n') {
		cout << "byebye" << endl;
	}
	

	while (1){

			cout << "> " << flush;
			cin >> num;

		switch (num) {
			case 0:
				cout << "Hope to see you again!!" << endl;
				return 0;
			case 1:
				set.inputFile();
				break;
			case 2:
			//1	set.unionFile();
				break;
			case 3:
				set.subtractFile();
				break;
			case 4:
				set.differenceFile();
				break;
			case 5:
				set.intersectFile();
				break;
			case 6:
				set.resetSet();
				break;
			case 7:
				set.outputFile();
				break;
			case 8:
                set.printSet();
				break;
			case 9:
			//	set.findItem();
				break;
			case 10:
			//	set.insertItem();
				break;
			case 11:
			//	set.deleteItem();
				break;
			case 12:
				set.verboseOutput();
				break;
			case 13:
				set.normalOutput();
				break;
			case 14:
				set.silentOutput();
				break;
			case 15:
				set.help();
				break;
			default: 
				cout << "in valid command" << endl;

		
		}
			
    }

	return 0;
  

}

