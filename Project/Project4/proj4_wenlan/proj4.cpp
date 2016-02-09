#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

bool silent=false;
bool verbose=false;

template <class T> class MySet;
template <class T> ostream& operator<<(ostream&, const MySet<T>);
template <class T> istream& operator>>(istream&, MySet<T> &);
template <class T> int operator==(const MySet<T> &, const MySet<T> &);
template <class T> int operator<(const MySet<T> &, const MySet<T> &);  //proper subset

template <class T> class MyMultiSet;
template <class T> ostream& operator<<(ostream&, const MySet<T>);
template <class T> istream& operator>>(istream&, MySet<T> &);
template <class T> int operator==(const MySet<T> &, const MySet<T> &);
template <class T> int operator<(const MySet<T> &, const MySet<T> &);  //proper subset

template <class T> class MySet{
	protected:
		vector<T> current;
		unsigned int location;

	public:
		friend ostream & operator<< <>(ostream &, const MySet<T>);  //stream out
		friend istream & operator>> <>(istream &, MySet<T> &);  //stream in
		friend int operator==<> (const MySet<T> &, const MySet<T> &);  //equality
		friend int operator< <>(const MySet<T> &, const MySet<T> &);  //proper subset

		MySet();
		void clear();
		void print();
		bool find(T);
		void addElt(T);
		bool deleteElt(T);
		T get_name(int);
		int size();
		int get_location();
		void output(string, MySet<T> &);
		bool readSet(MySet<T> &);
		void workWithSets(T &, string &);

		int compare(MySet<T> &);

		MySet<T> operator+(const MySet<T> &) const;  //union
		MySet<T> operator-(const MySet<T> &) const;  //subtraction
		MySet<T> operator*(const MySet<T> &) const;  //intersect
		MySet<T> operator^(const MySet<T> &) const;  //difference
		MySet<T> & operator=(const MySet<T> &);  //deep copy

/*
		MySet<T> operator+=(const MySet<T> &);  //union
		MySet<T> operator-=(const MySet<T> &);  //subtraction
		MySet<T> operator*=(const MySet<T> &);  //intersect
		MySet<T> operator^=(const MySet<T> &);  //difference
		int & operator<=(const MySet<T> &);  //subset
*/

};

template<class T> class MyMultiSet : public MySet<T>{
	private:
		vector<int> count;
						
	public:
//		friend ostream & operator<< <>(ostream &, const MyMultiSet<T>);  //stream out
//		friend istream & operator>> <>(istream &, MyMultiSet<T> &);  //stream in
//		friend int operator==<> (const MyMultiSet<T> &, const MyMultiSet<T> &);  //equality
//		friend int operator< <>(const MyMultiSet<T> &, const MyMultiSet<T> &);  //proper subset

		MyMultiSet();
		void clear();
		void print();
		void insert_item(T, int);
		bool delete_item(T);
		int reduce(T, int);
		int item_count(T);
		int get_count(int);
		MyMultiSet<T> operator+(const MyMultiSet<T> &) const;  //union
		MyMultiSet<T> operator-(const MyMultiSet<T> &) const;  //subtraction
		MyMultiSet<T> operator*(const MyMultiSet<T> &) const;  //intersect
		MyMultiSet<T> operator^(const MyMultiSet<T> &) const;  //difference

		MyMultiSet<T> & operator=(const MyMultiSet<T> &);  //deep copy

};



template <class T> MySet<T>::MySet():location(0) {
}

template <class T> 
void MySet<T>::clear() {current.clear();}


template <class T> 
void MySet<T>::print() {
	for (int i = 0; i < this->current.size(); ++i)
	{
		cout << this->current[i];
	}
}


template <class T> 
bool MySet<T>::find(T item) {
	for (int i = 0; i < current.size(); i++){
		if (current[i] == item) {
			location = i;
			return true;;
		}
	}
	return false;
}

template <class T> 
void MySet<T>::addElt(T item) {
	if (!find(item)){
		current.push_back(item);
	}
}

template <class T> 
bool MySet<T>::deleteElt(T item) {
	bool found = find(item);
	if (found){
		current.erase(current.begin()+location);
	}
	return found;
}

template <class T> 
int MySet<T>::compare(MySet<T> & yourSet) {
	if(*this==yourSet){
		return 0;
	}else if((*this < yourSet)==1){
		return -1;
	}else if((yourSet < *this)==1){
		return 1;
	}else {
		return 2;
	}
}


template <class T> 
T MySet<T>::get_name(int i) {
	return current[i];
}

template <class T> 
int MySet<T>::size() {
	return this->current.size();
}

template <class T> 
int MySet<T>::get_location() {
	return location;
}

//operator overloading

//union
template <class T> 
MySet<T> MySet<T>::operator+(const MySet<T> & yourSet) const {

	MySet <T> mySet;
	for (int i =0; i< this->current.size(); i++){
		mySet.current.push_back(this->current[i]);
	}


	for (int i =0; i < yourSet.current.size(); i++){
		bool found = false;

		for (int j=0; j < mySet.current.size(); j++){
			if (yourSet.current[i]==mySet.current[j]){
				found = true;
			}
		}

		if(found==false){
			mySet.current.push_back(yourSet.current[i]);
		}
	}
		
	if (!silent){
		cout << "Union completed" << endl;
	}
	
	return mySet;
}

//subtraction
template <class T> 
MySet<T> MySet<T>::operator-(const MySet<T> & yourSet) const{

	MySet <T> mySet;

	for (int i =0; i< this->current.size(); i++){
		mySet.current.push_back(this->current[i]);
	}

	for (int i =0; i < yourSet.current.size(); i++){

		for (int j=0; j < mySet.current.size(); j++){
			if (yourSet.current[i]==mySet.current[j]){
				mySet.current.erase(mySet.current.begin()+j);
			}
		}
	}
		
	if (!silent){
		cout << "Subtract completed" << endl;
	}
	
	return mySet;

}

 //intersect
template <class T> 
MySet<T> MySet<T>::operator*(const MySet<T> & yourSet) const{
	MySet <T> mySet;

	for (int i =0; i < yourSet.current.size(); i++){

		for (int j=0; j < this->current.size(); j++){
			if (yourSet.current[i]==this->current[j]){
				mySet.current.push_back(yourSet.current[i]);
			}
		}

	}

		
	if (!silent){
		cout << "Intersect completed" << endl;
	}
	
	return mySet;
}

//difference
template <class T> 
MySet<T> MySet<T>::operator^(const MySet<T> & yourSet) const{
	MySet <T> mySet;

	for (int i =0; i < yourSet.current.size(); i++){
		bool found = false;

		for (int j=0; j < this->current.size(); j++){
			if (yourSet.current[i]==this->current[j]){
				found = true;
			}
		}

		if(!found){
			mySet.current.push_back(yourSet.current[i]);
		}

	}

	for (int i =0; i < this->current.size(); i++){
		bool found = false;

		for (int j=0; j < yourSet.current.size(); j++){
			if (this->current[i]==yourSet.current[j]){
				found = true;
			}
		}

		if(!found){
			mySet.current.push_back(this->current[i]);
		}
	}

		
	if (!silent){
		cout << "Difference completed" << endl;
	}
	
	return mySet;

}

//deep copy
template <class T> 
MySet<T> & MySet<T>::operator=(const MySet<T> & yourSet){
	this->clear();

	for(int i =0; i< yourSet.current.size();i++){
		this->current.push_back(yourSet.current[i]);
	}
	return *this;
}

//equality
template <class T> 
int operator==(const MySet<T> & mySet, const MySet<T> & yourSet){

	if(mySet.current.size()!=yourSet.current.size()){
		return 0;
	}else{
		for(int i =0; i< mySet.current.size(); i++){
			bool found = false;
			for(int j =0; j< yourSet.current.size(); j++){
				if(mySet.current[i]==yourSet.current[j]){
					found = true;
				}
			}
			if(!found){
				return 0;
			}			
		}
		return 1;

	}
	
}

//proper subset
template <class T> 
int operator < (const MySet<T> & mySet,const MySet<T> & yourSet){

	if(mySet.current.size() < yourSet.current.size()){
		for(int i =0; i< mySet.current.size(); i++){
			bool found = false;
			for(int j =0; j< yourSet.current.size(); j++){
				if(mySet.current[i]==yourSet.current[j]){
					found = true;
				}
			}
			if(!found){
				return 0;
			}			
		}
		return 1;

	}else{
		return 0;
	}


}


template <class T> 
ostream & operator<<(ostream & os, const MySet<T> mySet){
	for (int i = 0; i < mySet.current.size(); i++){
		os << mySet.current[i] << endl;
	}
	return os;

}
template <class T> 
istream & operator>>(istream & is, MySet<T> &mySet){

	T temp;
	is >> temp;
	mySet.current.push_back(temp);
	return is;
}


/////////////////////////////////////////////////MULTISET//////////////////////////////////////
template <class T> MyMultiSet<T>::MyMultiSet() {
}

template <class T> void MyMultiSet<T>::clear() {
	this->current.clear();
	count.clear();
}

template <class T> void MyMultiSet<T>::print() {
	for (int i = 0; i < this->current.size(); i++){
		cout << count[i] << " " << this->current[i] << endl;
	}
}

template <class T> void MyMultiSet<T>::insert_item(T item, int num){
	if (this->find_item(item)){
		count[this->location] += num;
	} else{
		this->current.push_back(item);
		count.push_back(num);
	}
}

template <class T> bool MyMultiSet<T>::delete_item(T item){
	bool found = this->find_item(item);
	if (found){
		this->current.erase(this->current.begin()+this->location);
		count.erase(count.begin()+this->location);
	}
	return found;
}

template <class T> int MyMultiSet<T>::reduce(T item, int num){
	if (this->find_item(item)){
		if (count[this->location] <= num){
			delete_item(item);
			return 1;				//item deleted
		} else {
			count[this->location] -= num;
			return 0;				//item reduced
		}
	} else{
		return 2;					//item not found
	}
}

//extra helper function that will return the count associated with a given item
template <class T> int MyMultiSet<T>::item_count(T item){
	if (this->find_item(item)) {
		return count[this->location];
	}
	else {
		return 0;
	}
}

template <class T> int MyMultiSet<T>::get_count(int i){
	return count[i];
}

//union
template <class T> 
MyMultiSet<T> MyMultiSet<T>::operator+(const MyMultiSet<T> & yourMultiSet) const {

	MyMultiSet <T> myMultiSet;
	for (int i =0; i< this->current.size(); i++){
		myMultiSet.current.push_back(this->current[i]);
		myMultiSet.count.push_back(this->current[i]);
	}


	for (int i =0; i < yourMultiSet.current.size(); i++){
		bool found = false;

		for (int j=0; j < myMultiSet.current.size(); j++){
			if (yourMultiSet.current[i]==myMultiSet.current[j]){
				myMultiSet.count[j]+= yourMultiSet.count[i];
				found = true;
			}
		}

		if(!found){
			myMultiSet.current.push_back(yourMultiSet.current[i]);
			myMultiSet.count.push_back(yourMultiSet.count[i]);
		}
	}
		
	if (!silent){
		cout << "Union completed" << endl;
	}
	
	return myMultiSet;
}

//subtraction
template <class T> 
MyMultiSet<T> MyMultiSet<T>::operator-(const MyMultiSet<T> & yourMultiSet) const{

	MyMultiSet <T> myMultiSet;

	for (int i =0; i< this->current.size(); i++){
		myMultiSet.current.push_back(this->current[i]);
	}

	for (int i =0; i < yourMultiSet.current.size(); i++){

		for (int j=0; j < myMultiSet.current.size(); j++){
			if (yourMultiSet.current[i]==myMultiSet.current[j]){
				if(myMultiSet.count[j] > yourMultiSet.count[i]){
					myMultiSet.count[j] -= yourMultiSet.count[i];
				}else{
					myMultiSet.current.erase(myMultiSet.current.begin()+j);
					myMultiSet.count.erase(myMultiSet.count.begin()+j);
				}
			}
		}

	}
		
	if (!silent){
		cout << "Subtract completed" << endl;
	}
	
	return myMultiSet;
}

 //intersect
template <class T> 
MyMultiSet<T> MyMultiSet<T>::operator*(const MyMultiSet<T> & yourMultiSet) const{
	MyMultiSet <T> myMultiSet;

	for (int i =0; i < yourMultiSet.current.size(); i++){

		for (int j=0; j < this->current.size(); j++){
			if (yourMultiSet.current[i]==this->current[j]){
				myMultiSet.current.push_back(yourMultiSet.current[i]);
				if(yourMultiSet.count[i] > this->count[j]){
					myMultiSet.count.push_back(this->count[j]);
				}else{
					myMultiSet.count.push_back(yourMultiSet.count[i]);
				}
			}
		}

	}
	
	if (!silent){
		cout << "Intersect completed" << endl;
	}

	return myMultiSet;
}

//difference
template <class T> 
MyMultiSet<T> MyMultiSet<T>::operator^(const MyMultiSet<T> & yourMultiSet) const{
	MyMultiSet <T> myMultiSet;

	for (int i =0; i < yourMultiSet.current.size(); i++){
		bool found = false;
		for (int j=0; j < this->current.size(); j++){
			if (yourMultiSet.current[i]==this->current[j]){
				if(yourMultiSet.current[i]!=this->count[j]){
					myMultiSet.current.push_back(yourMultiSet.current[i]);
					myMultiSet.count.push_back(abs(yourMultiSet.current[i]-this->count[j]));
				}else{
					myMultiSet.current.erase(myMultiSet.current.begin()+j);
					myMultiSet.count.erase(myMultiSet.count.begin()+j);
				}
				found = true;
			}
		}

		if(!found){
			myMultiSet.current.push_back(yourMultiSet.current[i]);
			myMultiSet.count.push_back(yourMultiSet.count[i]);
		}
	}

	for (int i =0; i < this->current.size(); i++){
		bool found = false;

		for (int j=0; j < yourMultiSet.current.size(); j++){
			if (this->current[i]==yourMultiSet.current[j]){
				found = true;
			}
		}

		if(!found){
			myMultiSet.current.push_back(this->current[i]);
			myMultiSet.count.push_back(this->count[i]);
		}
	}
		
	if (!silent){
		cout << "Difference completed" << endl;
	}
	
	return myMultiSet;
}

//deep copy
template <class T> 
MyMultiSet<T> & MyMultiSet<T>::operator=(const MyMultiSet<T> & yourMultiSet){
	this->clear();

	for(int i =0; i< yourMultiSet.current.size();i++){
		this->current.push_back(yourMultiSet.current[i]);
		this->count.push_back(yourMultiSet.count[i]);
	}
	return *this;
}


//============================================================================
// Name        : testP4main.cpp
// Author      : Richard Newman
// Version     : 1
// Copyright   : 
// Description : testing generic type sets for project 4
// 		must include Proj4.h header with set templates and 
//		operator overloads
//============================================================================


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
  unused,				// 12 - for reduce
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
	  while(!is.eof()){
    is >> ms;
	  }

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
/*
    	case set_difference://difference
    	{
		MySet<T> otherSet;
      		if (readSet(otherSet))
		{
		  currentSet = currentSet ^ otherSet;
		}
    		break;
    	}
*/
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

