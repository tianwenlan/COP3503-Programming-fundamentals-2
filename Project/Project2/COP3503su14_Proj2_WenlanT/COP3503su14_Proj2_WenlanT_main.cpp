/* Proj2.cpp
 * Author: Wenlan Tian
 * Date:06-17-2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "COP3503su14_Proj2_WenlanT_main.h"
#include "COP3503su14_Proj2_WenlanT_multiSet.h"

using namespace std;

int main(int argc, char *argv []){	

	MultiSet myMultiSet;
    
	int num;
	string itemName;
	string inFileName;
	int count;

	bool first = true;
	myMultiSet.verbose=false;

	for (int i = 1; i < argc; i++) { 	// parse cmdline args
		if (argv[i][0] == '-'){
			if (argv[i] == SOPT) {
				myMultiSet.silent = true;
				myMultiSet.verbose = false;
			}else if (argv[i] == VOPT) {
				myMultiSet.verbose = true; 
				myMultiSet.silent = false;
				verboseOutput();
			}else if (argv[i] == HOPT) {
				cout << HELP << endl;
			}else if (argv[i] == FOPT){
				if (i < argc){
					inFileName = argv[i + 1];
					myMultiSet.inputFile(inFileName);
				}
			}else{
				if(!myMultiSet.silent){
				cerr << "Invalid commandline argument: " << argv[i] << endl;
				}
			}
		}else if(argv[i-1]!=FOPT){
			if(!myMultiSet.silent){
			cerr << "Invalid commandline argument: " << argv[i] << endl;
			}
			return -1;
		}

  }


	while (1){
		if (myMultiSet.verbose&&!first){
			verboseOutput();
		}
		first = false;
		if (!myMultiSet.silent){
			cout << "> " << flush;
		}
		cin >> num;
		while (cin.fail()){
        cin.clear();
        cin.ignore();
        cerr << "Not a valid number. Please reenter a number: ";
		cin >> num;
		}

		switch (num) {
			case 0:
				return 0;
			case 1:
				cin >> inFileName;
				myMultiSet.inputFile(inFileName);
				break;
  	    	case 2:
				myMultiSet.unionSets();
				break;
			case 3:
				myMultiSet.subtractSets(); 
   				break;
			case 4: 
				myMultiSet.differenceSets();
				break;
			case 5:
				myMultiSet.intersectSets();   
				break;
			case 6:
				myMultiSet.reset();
				break;
			case 7:
				myMultiSet.printToFile();
				break;
		    case 8:
				myMultiSet.print();
				break;
    		case 9:
				myMultiSet.findItem(itemName);
				break;
			case 10:
				myMultiSet.insertItem(itemName,count);
				break;
			case 11:
				myMultiSet.deleteItem(itemName);
				break;
			case 12:
				myMultiSet.reduceItem(itemName,count);
				break;
			case 13:
				myMultiSet.verbose = true;
				myMultiSet.silent = false;
				break;
			case 14:
                myMultiSet.verbose = false;
				myMultiSet.silent = false;
				break;
			case 15:
				myMultiSet.silent = true;
				myMultiSet.verbose = false; 
				break;                   
			case 16:
				cout << HELP << endl;
				break;
			case 17:
				myMultiSet.maxSets();
				break;
			default:
				if (!myMultiSet.silent){
				cerr << "Invalid command" << endl;
				}
		}			
    }
   return 1;
}
