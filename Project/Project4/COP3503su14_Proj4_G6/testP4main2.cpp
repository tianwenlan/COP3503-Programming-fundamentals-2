//============================================================================
// Name        : testP4main2.cpp
// Author      : Richard Newman
// Version     : 1
// Copyright   : 
// Description : testing generic type multisets for project 4
//============================================================================

#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
// include header with appropriate templates
#include "Proj4.h"


using namespace std;

bool silent=false;
bool verbose=false;


enum operation

{
  time_to_exit,          //  0
  mset_from_file,        //  1
  mset_add,              //  2
  mset_subtract,         //  3
  mset_difference,       //  4
  mset_intersect,        //  5
  mset_reset,            //  6
  mset_write,            //  7
  mset_print,            //  8
  mset_find_item,        //  9
  mset_insert_item,      // 10
  mset_delete_item,      // 11
  mset_reduce_item,	 // 12 
  mode_verbose,          // 13
  mode_normal,           // 14
  mode_silent,           // 15
  mprint_help,           // 16
  mset_compare,          // 17
  mset_equal,            // 18
  mset_less_than,         // 19
  mset_add2,             // 20  +=
  mset_subtract2,       // 21   -=
  mset_difference2,      // 22  ^=
  mset_intersect2,       // 23  *=
  mset_subset            // 24  <=

};

template <typename T>

void output(string output_fname, MyMultiSet<T> &m)
  {
  ofstream Ofile(output_fname.c_str());
  if (Ofile.is_open())// write to a file
  {
    Ofile << m;
    //if (!silent)
      //cout << "Save to " << output_fname << " completed" << endl;
  }
  else cout << "Unable to open file: "<<output_fname<<endl;
  Ofile.close();
}


template <typename T>
bool input(MyMultiSet<T> &m)
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
    is >> m;
    retVal = !(is.bad());
  }
  else
  {
    cout << "Unable to open file: "<< filename << endl;
  }
  is.close();
  return retVal;



}

const string MS_NORMAL_PROMPT="Multisets > ";
const string MS_VERBOSE_PROMPT=
        "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;\n"
        "4 - difference <file>; 5 - intersect <file>; *6 - reset current multiset;\n"
        "7 - write <file>; 8 - print; *9 - find <item>; "
        "*10 - insert <item>; *11 - delete <item>;\n" 
        "13 - verbose; 14 - normal; 15 - silent; 16 - help\n"
        "*17 - compare <file>; 18 - equal <file>; 19 - less than <file>\n"
	"* - these commands may or may not be implemented\n"
        "> ";
const string MS_HELP_STRING=
        "======================================================================\n"
        "The numbered multiset commands are as follows:\n"
        "0. exit\n"
        "1. input file <filename>: open and read a multiset from a file to the current list\n"
        "2. union file <filename>: open and union a multiset from a file with the current multiset\n"
        "3. subtract file <filename>: open and subtract multiset from a file from the current multiset\n"
        "4. difference file <filename>: open and find the difference between a multiset from a file and the current multiset\n"
        "5. intersect file <filename>: open and find the intersection between a multiset from a file and the current multiset\n"
        "*6. reset current multiset to the empty multiset\n"
        "7. output file <filename>: open and write the current multiset to a file\n"
        "8. print current multiset to the console\n"
        "*9. find <item name>: test if <item name> is in the current multiset\n"
        "*10. insert <item name>: add <item name> to the current multiset if it is not already in it\n"
        "*11. delete <item name>: remove <item name> from the current multiset if it is in it\n"
        "13. verbose output\n"
        "14. normal output\n"
        "15. silent output\n"
        "16. help\n"
        "*17. compare <file>: read a multiset from a file, print\n"
	"\t -1 if current multiset is properly contained in the new multiset\n"
	"\t  0 if current multiset is identical to the new multiset\n"
	"\t  1 if current multiset is properly contains the new multiset\n"
	"\t  2 if current multiset and the new multiset are not comparable\n"
        "18. equal <file>: read a multiset from a file, print 1 if current multiset is equal to the new multiset, else 0\n"
        "19. less than <file>: read a multiset from a file, print 1 if current multiset is properly contained in the new multiset, else 0\n"
	"* - these commands may or may not be implemented\n"
        "======================================================================\n";

template <typename T> 
void workWithMultiSets(T &typeHolder, string &tName)
{
  //init
  int operation_num;
  bool run=true;
  string prompt = tName + MS_NORMAL_PROMPT;
  MyMultiSet<T> currentMultiSet;
	
  if (!silent)
  	cout<<MS_HELP_STRING<<endl;

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

      	case mset_from_file://input file
      	{
      		if (input(currentMultiSet) && !silent)
			cout << "New multiset loaded" << endl;
        	// int max = currentMultiSet.size();
        	// if (verbose) cout << "Current multiset size = " << max << endl;
      		break;
      	}

    	case mset_add://union
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
    		  currentMultiSet = currentMultiSet + otherMultiSet;
		}
    		break;
    	}

    	case mset_subtract://substract
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
    		  currentMultiSet = currentMultiSet - otherMultiSet;
		}
    		break;
    	}

    	case mset_difference://difference
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
		  currentMultiSet = currentMultiSet ^ otherMultiSet;
		}
    		break;
    	}

    	case mset_intersect://intersect
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
		  currentMultiSet = currentMultiSet * otherMultiSet;
		}
    		break;
    	}

    	case mset_reset://reset
	  	 currentMultiSet.clear();
	  	// if (!silent)
	    	  // cout << "Reset completed"<<endl;
    	  	break;

    	case mset_write://output
    	{
    		string output_filename;
    		cin >> output_filename;
    		output(output_filename, currentMultiSet);
    		break;
    	}

    	case mset_print://print
    	{
                // int max = currentMultiSet.size();
                // if (verbose) cout << "Current multiset size = " << max << endl;
                cout << currentMultiSet;
    		break;
    	}
    	case mset_find_item://find item
    	{
/*
    		T item_name;
		MultiSetItem *foundItem;

    		cin >> item_name;
		if (!silent)
    			cout << "Item " << item_name;
		MultiSetItem newItem = MultisetItem(item_name,0);
    		if(foundItem = currentMultiSet.find(newItem))
	        {
	          if (!silent)
	            cout << " found with count "
	                 << foundItem->getCount()
	                 << endl;
	        }
	        else
	        {
	          if (!silent)
	            cout << " not in set" <<endl;
	        }
*/
    		break;
    	}
    	case mset_insert_item://insert item
    	{

/*
    		T item_name;
		int item_count;

    		cin >> item_name;
		if (!silent)
    			cout << "Item " << item_name;
    		cin >> item_count;
		MultiSetItem newItem = MultisetItem(item_name,item_count);
		int newCount = currentSet.insertItem(newItem);
		if (!silent)
		{
		  cout << " inserted with count ";
		  cout << newCount << end;
		}
*/
    		break;
    	}
    	case mset_delete_item: //delete item
    	{
/*
    		T item_name;

    		cin >> item_name;
		if (!silent)
    			cout << "Item " << item_name;
		MultiSetItem newItem = MultisetItem(item_name,0);
    		if(currentMultiSet.deleteItem(newItem))
	        {
	          if (!silent)
	            cout << " not in set" << endl;
	        }
	        else
	        {
	          if (!silent)
	            cout << " deleted" <<endl;
	        }
*/
    		break;
    	}
    	case mode_verbose:  // verbose
    		verbose = true;
    		silent = false;
    		prompt = MS_VERBOSE_PROMPT;
    		break;
    	case mode_normal:  // normal 
    		verbose = false;
    		silent = false;
    		prompt = tName + MS_NORMAL_PROMPT;
    		break;
    	case mode_silent:  // silent 
    		verbose = false;
    		silent = true;
    		prompt = "";
    		break;
    	case mprint_help:
    		cout << MS_HELP_STRING << endl;
    		break;
    	case mset_compare: // compare
	{

		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
    		  cout << currentMultiSet.compare(otherMultiSet) << endl;

    		break;
	}
    	case mset_equal: // equal 
	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
    		  cout << (currentMultiSet == otherMultiSet) << endl;
    		break;
	}
    	case mset_less_than: // contained in
	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
    		  cout << (currentMultiSet < otherMultiSet) << endl;
    		break;
	}

	  	case mset_add2://union  +=
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
    		  currentMultiSet += otherMultiSet;
		}
    		break;
    	}

    	case mset_subtract2://substract  -=
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
    		  currentMultiSet -= otherMultiSet;
		}
    		break;
    	}

    	case mset_difference2://difference  ^=  
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
		  currentMultiSet ^= otherMultiSet;
		}
    		break;
    	}

    	case mset_intersect2://intersect  *=
    	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
		{
		  currentMultiSet *= otherMultiSet;
		}
    		break;
    	}

		case mset_subset: // <=
	{
		MyMultiSet<T> otherMultiSet;
      		if (input(otherMultiSet))
    		  cout << (currentMultiSet <= otherMultiSet) << endl;
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
  	cout << MS_HELP_STRING << endl;
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
  	workWithMultiSets(indicator, s);
  	break;
        }
  
        case (characters):
        {
  	cout << "Characters it is!" << endl;
  	char indicator;
  	string s("Char ");
  	workWithMultiSets(indicator, s);
  	break;
        }
  
        case (strings):
        {
  	cout << "Strings it is!" << endl;
  	string indicator;
  	string s("String ");
  	workWithMultiSets(indicator, s);
  	break;
        }
  
        case (doubles):
        {
  	cout << "Doubles it is!" << endl;
  	double indicator;
  	string s("Double ");
  	workWithMultiSets(indicator, s);
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
