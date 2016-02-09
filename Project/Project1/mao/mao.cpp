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

  class Set
  {
	  public:
      void reset();
      void print();
      void printToFile();
      int  getLength();
      string  getValue(int index);
      int  findItem(string &itemName);
      bool insertItem(string &value);
      bool deleteItem(string &value);                
      bool inputFile(); 
      bool unionSets(Set &peerSet);
      bool subtractSets(Set &peerSet);
      bool differenceSets(Set &peerSet);
      bool intersectSets(Set &peerSets);
	  void verboseOutput();
	  void help();
 
      Set();  
         
      string setArray[100];
      int length;
      int maxLength;
	  bool verbose = true;
      bool silent = false;



//case 1: empty the current set, and fill it with the set from a file
  bool Set::inputFile(){
	   string inFileName;
       string tempString;
       ifstream inStream;

	   cin >> inFileName;
      
       inStream.open(inFileName.c_str(), ifstream::in);        
       if(!inStream.is_open()) {
		   if (!silent)
           cout << "File " << inFileName << " cannot be opened!" << endl;
	       return false;
       }
       if(inStream.fail()) {
           cout << "Error: open operation failed!" << endl;
	       return false;
       }
       
       while(inStream >> tempString){
	 	   insertItem(tempString);
       }
	   tempString.cler();
       if (!silent)
       cout << "New Set Loaded" << endl;
       return true;
  }
/*
//case 6:reset current set to the empty set
  void Set::reset(){
      int i;
      for (i = 0; i < maxLength; i++){
          setArray[i] = std::string("");
      }
      length = 0;
	  if (!silent)
      cout << "Reset completed" << endl;
  }
*/

//case 7: open and write the current set to a file   
  void Set::printToFile(){
	   string outFileName;
       ofstream output;
	   int i;

	   cin >> outFileName;
       output.open(outFileName.c_str());
	   if (output.fail()){
		  if (!silent)
		  cout << "File " << outFileName << " cannot be opened" << endl;
	   }
	   
       for (i = 0; i < length; i++)
       {
          output <<setArray[i].c_str() << endl;
       } 
	      if (!silent)
	      cout << "Save to " << outFileName << " completed" << endl;
       
  } 

//case 8: print current set to the console
  void Set::print(){
      int i;
      for (i = 0; i < length; i++)
      {
          cout <<setArray[i].c_str() << endl;
      } 
  }

  
  int Set::getLength(){
      return length;
  }
  
  std::string Set::getValue(int index){
      return setArray[index];
  }
  
//case 2: open and union a set from a file with the current set  
  bool Set::unionSets(Set &peerSet){
      int i;
      string tempValue;
      int len = peerSet.getLength();

      for (i=0; i < len; i++){
          tempValue = peerSet.getValue(i);
	  this->insertItem(tempValue);
      }
	  tempValue.clear();
	  if (!silent)
      cout << "Union Completed!" << endl;
      return true;
  }

//case 3: open and subtract set from a file from the current set
  bool Set::subtractSets(Set &peerSet){

      int i;      
      string tempValue;
      int len = peerSet.getLength();
      for (i=0; i < len; i++){
          tempValue = peerSet.getValue(i);
	      this->deleteItem(tempValue);
      }
	  if (!silent)
      cout << "Subtraction Completed!" << endl; 
      return true;
	  
  }

//case 4: open and find the difference between a set from a file and the current set
  bool Set::differenceSets(Set &peerSet){
      int i;      
      string tempValue;
      int len = peerSet.getLength();
      for (i=0; i < len; i++){
          tempValue = peerSet.getValue(i);
		  if( this->findItem(tempValue) == -1){
	          this->insertItem(tempValue);
		  }else{
	          this->deleteItem(tempValue);
	      }
      }
	  if(!silent)
      cout << "Difference Completed!" << endl;
      return true;
  } 

//case 5: open and find the intersection between a set from a file and the current set  
  bool Set::intersectSets(Set &peerSet){
      int i;      
      string tempValue;
      int len = this->getLength();
      for (i= len -1; i >= 0; i--){
          tempValue = this->getValue(i);
		  if( peerSet.findItem(tempValue) == -1){
	      this->deleteItem(tempValue);
	      }
      }
	  if(!silent)
      cout << "Intersetction Completed!" << endl;
      return true; 
  }

//case 9: test if a given item is in the current set
  int Set::findItem(string &itemName){
      int i;
      for (i = 0; i < length; i++){
          if(setArray[i] == itemName){
			  if(!silent)
	          cout << "Item " << itemName << " found"  << endl;
	          return i;
	      }
      }
		  if(!silent)
          cout << "Item " << itemName << " not found" << endl;
          return -1;
  }

//case 10: add an item to the current set if it is not already in it
  bool Set::insertItem(string &itemName){
      int i;
      int j;
      
      i = findItem(itemName);      
      if ( i != -1){
		  if (!silent)
          cout << "Item " << itemName << " already in set" << endl;
	      return true;
      }else if(length == maxLength){
		  if (!silent)
	      cout << "Error: setArray overflow" << endl;
	      return false;
      }      
      setArray[length] = itemName;
      length++;
	  if (!silent)
	  cout << "Item " << itemName << " inserted" << endl;
      return true;
  }

//case 11: remove and item from the current set if it is in it
  bool Set::deleteItem(string &value){
      int i;
      
      i = findItem(value);
      if( i != -1){
          while(i < (length-1) ){
	      setArray[i] = setArray[i+1];
	      i++;
	  }
	  setArray[length-1] = string("");
	  length--;
	      if(!silent)
	      cout << "Item " << value << " deleted" << endl;
      }else{
          cout << "Item " << value << " not in set" << endl;
      }
      return true;
  }

  
  Set::Set():length(0),maxLength(100){
  }

//case 12: get verbose output
  void Set::verboseOutput(){
	  		cout << "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;" << endl;
            cout << "4 - difference <file>; 5 - intersect <file>; 6 - reset current set" << endl;
            cout << "7 - write <file>; 8 - print; 9 - find <item>; 10 - insert <item>;" << endl;
            cout << "11 - delete <item>; 12 - verbose; 13 - normal; 14 - silent; 15 - help;" << endl;
  }


//case 15: get help information
  void Set::help(){
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


//main function

int main()
{
   
    Set mySet;
    Set urSet;
    
    Set &refUrSet = urSet;
   
   	char answer;
	int num;
	string itemName;
	string inFileName;

	bool verbose = true;
	bool silent = false;

	cout << "Welcome to use my first program!! " << endl;
	cout << "There are 0-15 different numbers with different functions" << endl;
	cout << "Would you like to see a list of the numbers and how they are to be used? y/n" << endl;
    
	cin >> answer;

	if (answer == 'y'){
		mySet.help();
	}
	

	while (1){
            if (!silent)
			cout << "> " << flush;
			cin >> num;

		switch (num) {
			case 0:
				cout << "Hope to see you again! BYE!!" << endl;
				return 0;
			case 1:
                mySet.inputFile();
				break;
  	    	case 2:
                urSet.inputFile();
                mySet.unionSets(refUrSet);
				break;
			case 3:
				urSet.inputFile();  
				mySet.subtractSets(refUrSet); 
   				break;
			case 4:
				urSet.inputFile();  
				mySet.differenceSets(refUrSet);
				break;
			case 5:
				urSet.inputFile();  
				mySet.intersectSets(refUrSet);   
				break;
			case 6:
			//	mySet.reset();

				mySet.clear();
				break;
			case 7:
				mySet.printToFile();
				break;
			case 8:
                mySet.print();
				break;
     		case 9:
				cin >> itemName;
				mySet.findItem(itemName);
				break;
			case 10:
				cin >> itemName;
				mySet.insertItem(itemName);
				break;
			case 11:
				cin >> itemName;
				mySet.deleteItem(itemName);
				break;
			case 12:
				verbose = true;
				silent = false;
				mySet.verboseOutput();
				break;
			case 13:
                verbose = false;
				silent = false;
				break;
			case 14:
				silent = true;
				verbose = false; 
				break;                   
			case 15:
				mySet.help();
				break;
			default: 
				cout << "in valid command" << endl;

		
		}
			
    }


 
   
   return 1;
}
