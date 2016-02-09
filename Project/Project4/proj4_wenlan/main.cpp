//============================================================================
// Name        : testP4main.cpp
// Author      : Richard Newman
// Version     : 1
// Copyright   : 
// Description : testing generic type sets for project 4
// 		must include Proj4.h header with set templates and 
//		operator overloads
//============================================================================

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "Proj4.h"

using namespace std;

bool silent=false;
bool verbose=false;

enum operation
{
  time_to_exit,         //  0
  set_from_file,        //  1
  set_add,              //  2
  set_subtract,         //  3
  set_difference,       //  4
  set_intersect,        //  5
  set_reset,            //  6
  set_write,            //  7
  set_print,            //  8
  set_find_item,        //  9
  set_insert_item,      // 10
  set_delete_item,      // 11
  unused,		// 12 - for reduce
  mode_verbose,         // 13
  mode_normal,          // 14
  mode_silent,          // 15
  print_help,           // 16
  set_compare,          // 17
  set_equal,            // 18
  set_less_than         // 19

};

template <typename T>
void output(string output_fname, MySet<T> &s)
  {
  ofstream Ofile(output_fname.c_str());
  if (Ofile.is_open())// write to a file
  {
    Ofile << s;
    //if (!silent)
      //cout << "Save to " << output_fname << " completed" << endl;
  }
  else cout << "Unable to open file: "<<output_fname<<endl;
  Ofile.close();
}


template <typename T>
bool readSet(MySet<T> &ms)
{
  bool retVal = false;
  string filename;
  if (verbose)
    cout << "Input file name: " << flush;
  cin >> filename;
  if (verbose) cout << "Trying to open " << filename << endl;
  ifstream is(filename.c_str());
  if (is.is_open()) //read from a file
  {
    is >> ms;
    retVal = !(is.bad());
  }
  else
  {
    cout << "Unable to open file: "<< filename << endl;
  }
  is.close();
  return retVal;
}

const string S_NORMAL_PROMPT="Sets > ";
const string S_VERBOSE_PROMPT=
        "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;\n"
        "4 - difference <file>; 5 - intersect <file>; 6 - reset current set;\n"
        "7 - write <file>; 8 - print; 9 - find <item>; "
        "10 - insert <item>; 11 - delete <item>;\n" 
        "13 - verbose; 14 - normal; 15 - silent; 16 - help\n"
        "17 - compare <file>; 18 - equal <file>; 19 - less than <file>\n"
        "> ";
const string S_HELP_STRING=
        "======================================================================\n"
        "The numbered set commands are as follows:\n"
        "0. exit\n"
        "1. input file <filename>: open and read a set from a file to the current list\n"
        "2. union file <filename>: open and union a set from a file with the current set\n"
        "3. subtract file <filename>: open and subtract set from a file from the current set\n"
        "4. difference file <filename>: open and find the difference between a set from a file and the current set\n"
        "5. intersect file <filename>: open and find the intersection between a set from a file and the current set\n"
        "6. reset current set to the empty set\n"
        "7. output file <filename>: open and write the current set to a file\n"
        "8. print current set to the console\n"
        "9. find <item name>: test if <item name> is in the current set\n"
        "10. insert <item name>: add <item name> to the current set if it is not already in it\n"
        "11. delete <item name>: remove <item name> from the current set if it is in it\n"
        "13. verbose output\n"
        "14. normal output\n"
        "15. silent output\n"
        "16. help\n"
        "17. compare <file>: read a set from a file, print\n"
	"\t -1 if current set is properly contained in the new set\n"
	"\t  0 if current set is identical to the new set\n"
	"\t  1 if current set is properly contains the new set\n"
	"\t  2 if current set and the new set are not comparable\n"
        "18. equal <file>: read a set from a file, print 1 if current set is equal to the new set, else 0\n"
        "19. less than <file>: read a set from a file, print 1 if current set is properly contained in the new set, else 0\n"
        "======================================================================\n";

template <typename T> 
void workWithSets(T &typeHolder, string &tName)
{
  //init
  int operation_num;
  bool run=true;
  string prompt = tName + S_NORMAL_PROMPT;
  MySet<T> currentSet;
	
  if (!silent)
  	cout<<S_HELP_STRING<<endl;

  //operations
  while(run)
  {
    cout << prompt << flush;
    cin >> operation_num;
    if (cin.good()) 
    {
      switch (operation_num)
      {

      	case time_to_exit:
      		run = false;
      		break;

      	case set_from_file://input file
      	{
      		if (readSet(currentSet) && !silent)
			cout << "New set loaded" << endl;
        	int max = currentSet.size();
        	if (verbose) cout << "Current set size = " << max << endl;
      		break;
      	}
    	case set_add://union
    	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
		{
    		  currentSet = currentSet + otherSet;
		}
    		break;
    	}

    	case set_subtract://substract
    	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
		{
    		  currentSet = currentSet - otherSet;
		}
    		break;
    	}

    	case set_difference://difference
    	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
		{
		  currentSet = currentSet ^ otherSet;
		}
    		break;
    	}

    	case set_intersect://intersect
    	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
		{
		  currentSet = currentSet * otherSet;
		}
    		break;
    	}

    	case set_reset://reset
	  	currentSet.clear();
	  	if (!silent)
	    	  cout << "Reset completed"<<endl;
    	  	break;

    	case set_write://output
    	{
    		string output_filename;
    		cin >> output_filename;
    		output(output_filename, currentSet);
    		break;
    	}

    	case set_print://print
    	{
                int max = currentSet.size();
                if (verbose) cout << "Current set size = " << max << endl;
                cout << currentSet;
    		break;
    	}
    	case set_find_item://find item
    	{
    		T item_name;
    		cin >> item_name;
    		cout << "Item " << item_name;
    		if(currentSet.find(item_name)){
    			cout << " found" << endl;
    		}
    		else{
    			cout << " not found" <<endl;
    		}
    		break;
    	}
    	case set_insert_item://insert item
    	{
    		T item_name;
    		cin >> item_name;
    		cout << "Item " << item_name;
    		if(currentSet.find(item_name)){
    			cout << " already in set" << endl;
    		}
    		else{
    			currentSet.addElt(item_name);
    			cout << " inserted" << endl;
    		}
    		break;
    	}
    	case set_delete_item: //delete item
    	{
    		T item_name;
    		cin >> item_name;
    		cout << "Item " << item_name;
    		if(!currentSet.find(item_name)){
    			cout << " not in the set" << endl;
    			break;
    		}
		currentSet.deleteElt(item_name);
    		cout << " deleted" << endl;
    		break;
    	}
    	case mode_verbose:  // verbose
    		verbose = true;
    		silent = false;
    		prompt = S_VERBOSE_PROMPT;
    		break;
    	case mode_normal:  // normal 
    		verbose = false;
    		silent = false;
    		prompt = tName + S_NORMAL_PROMPT;
    		break;
    	case mode_silent:  // silent 
    		verbose = false;
    		silent = true;
    		prompt = "";
    		break;
    	case print_help:
    		cout << S_HELP_STRING << endl;
    		break;
    	case set_compare: // compare
	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
    		  cout << currentSet.compare(otherSet) << endl;
    		break;
	}
    	case set_equal: // equal 
	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
    		  cout << (currentSet == otherSet) << endl;
    		break;
	}
    	case set_less_than: // contained in
	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
    		  cout << (currentSet < otherSet) << endl;
    		break;
	}
    	default:
    		cout<<"Command is invalid"<<endl;
		cin.clear();
    		break;
      }  // end switch
    }  // end if
    else 
    {
	string garbage;
  	cin.clear();
	cin >> garbage;
      	cout << "Command " << garbage << " is invalid" << endl;
  	cout << S_HELP_STRING << endl;
    }
  }  // end while 

  return ;
}

enum setType {stop, integers, characters, strings, doubles, help};

int  main(int arg, char ** argc)
{
  bool run=true;
  const string prompt ("type > ");
  const string helpStr = "0-quit, 1-ints, 2-chars, 3-string, 4-doubles, 5-help";
  int type;

  cout << helpStr << endl;
  while (run) 
  {
    cout << prompt << flush;
    cin >> type;
    if (cin.good()) 
    {
      switch (type)
      {
        case (stop):
        {
  	run = false;
  	cout << "bye bye" << endl;
  	break;
        }
  
        case (integers):
        {
  	cout << "Integers it is!" << endl;
  	int indicator;
  	string s("Integer ");
  	workWithSets(indicator, s);
  	break;
        }
  
        case (characters):
        {
  	cout << "Characters it is!" << endl;
  	char indicator;
  	string s("Char ");
  	workWithSets(indicator, s);
  	break;
        }
  
        case (strings):
        {
  	cout << "Strings it is!" << endl;
  	string indicator;
  	string s("String ");
  	workWithSets(indicator, s);
  	break;
        }
  
        case (doubles):
        {
  	cout << "Doubles it is!" << endl;
  	double indicator;
  	string s("Doubls ");
  	workWithSets(indicator, s);
  	break;
        }
  
        case (help):
        {
  	cout << helpStr << endl;
  	break;
        }
  
        default:
        {
      	cout<< "Type is invalid" << endl;
  	cout << helpStr << endl;
  	cin.clear();
      	break;
        }
  
      }  // end switch
    }  // end if
    else
    {
	string garbage;
  	cin.clear();
	cin >> garbage;
      	cout << "Command " << garbage << " is invalid" << endl;
  	cout << helpStr << endl;
    }
  }  // end while

  return 0;
}
