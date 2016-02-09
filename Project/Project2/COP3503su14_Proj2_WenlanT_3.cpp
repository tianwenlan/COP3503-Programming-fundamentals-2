/* Proj2.cpp
 * Author: Wenlan Tian
 * Date:06-17-2014
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

	class Object{
		private:
		string name;
		int count;

		public:
		string getName();
		int getCount();
		void setName(string);
		void setCount(int);
	};

	class MultiSet{
		private:
		vector <Object> multiSet;
		int size;

		public:
		int reset();
		void print();
		int printToFile();
		int  findItem(string);
		void getInsert(string &, int &);
		int insertItem(string, int); 
		int deleteItem(string);
		int reduceItem(string, int);
		void inputFile(string ); 
		int unionSets();
		int subtractSets();
		int differenceSets();
		int intersectSets();
		int maxSets();
		int getSize();

		MultiSet();
	}; 


	bool verbose;
	bool silent;



	void verboseOutput();
	void menu();

	string Object::getName(){
		return this -> name;
	}

	int Object::getCount(){
		return this -> count;
	}

	void Object::setName(string name){
		this->name=name;
	}

	void Object::setCount(int count){
		this->count=count;
	}
  
	MultiSet::MultiSet():size(0){
	}

	int MultiSet::getSize(){
		return size;
	}


//case 1: empty the current multiset, and fill it with the multiset from a file
	void MultiSet::inputFile(string inFileName){
		ifstream inStream;
		Object o;
		string tempName;
		int tempCount;
		string line;

		multiSet.clear();
		size = 0;

		inStream.open(inFileName.c_str());        
		if(inStream.fail()) {
			if (!silent)
				cerr << "File " << inFileName << " cannot be opened!" << endl;
			return;
		}
		while (!inStream.eof()){
			// get next line from console
			while(getline(inStream,line)){
				// convert input line into a stream
				istringstream record(line);
				// read from stream a string and an int
				record >> tempName;
				record >> tempCount;

				// if the line has no printable chars
				// or if the second string is not a number
				// the input line is malformed
				if (record.fail()) {
					cerr << "Error: input failure" << endl;
					continue;
				}

				// now see if there is more stuff in the line
				if (!record.eof()){
					// try to read it
					record >> tempName;
					if (!record.fail())
					// if read a string, then bad line
					cout << "line malformed: " << line << endl;
					// if fail to read a string,
					// then just white space left,
					// no big deal
				}

				o.setName(tempName);
				o.setCount(tempCount);


				multiSet.push_back(o);
				size ++;	

				// reset tempName to empty so we don't print junk
				tempName = "";
			}
		}
/*

		while (!inStream.eof()){
			inStream >> tempName;
			o.setName(tempName);
			inStream >> tempCount;
			o.setCount(tempCount);
			multiSet.push_back(o);
			size ++;			
		}

		inStream.close();
*/		if (!silent){
			cout << "New Set Loaded" << endl;
		}
		
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
			if (!silent)
				cerr << "File " << inFileName << " cannot be opened!" << endl;			
		}
		while (!inStream.eof()){
			while(getline(inStream,line)){
				// convert input line into a stream
				istringstream record(line);
				// read from stream a string and an int
				record >> tempName;
				o.setName(tempName);
				record >> tempCount;
				o.setCount(tempCount);

				// if the line has no printable chars
				// or if the second string is not a number
				// the input line is malformed
				if (record.fail()) {
				cerr << "Error: input failure" << endl;
				// on input failure, just go to next line
				continue;
				}


				// now see if there is more stuff in the line
				if (!record.eof()){
				// try to read it
				record >> tempName;
				if (!record.fail())
				// if read a string, then bad line
				cout << "line malformed: " << line << endl;
				// if fail to read a string,
				// then just white space left,
				// no big deal
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
			}
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

		cin >> inFileName;

		inStream.open(inFileName.c_str());        
		if(inStream.fail()) {
				cerr << "Unable to open file: " << inFileName << endl;
				return;
		}
		while (!inStream.eof()){
			inStream >> tempName;
			o.setName(tempName);
			inStream >> tempCount;
			o.setCount(tempCount);

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

		cin >> inFileName;

		inStream.open(inFileName.c_str());        
		if(inStream.fail()) {
			if (!silent)
				cerr << "File " << inFileName << " cannot be opened!" << endl;			
		}
		while (!inStream.eof()){
			inStream >> tempName;
			o.setName(tempName);
			inStream >> tempCount;
			o.setCount(tempCount);
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
		int length =0;
		vector<int> index;
		int deleteLength=0;
		vector<int> deleteIndex;
		int sizeLength=0;
		vector<int> mySize;

		cin >> inFileName;

		inStream.open(inFileName.c_str());        
		if(inStream.fail()) {
			if (!silent)
				cerr << "File " << inFileName << " cannot be opened!" << endl;			
		}
		while (!inStream.eof()){
			inStream >> tempName;
			o.setName(tempName);

			inStream >> tempCount;
			o.setCount(tempCount);

			bool found = false;
			for (int i = 0; i < size; i++){
				if (multiSet[i].getName() == o.getName()){
					index.push_back(i);
					length++;
					if(multiSet[i].getCount() > o.getCount()){
						multiSet[i].setCount(o.getCount());				
						}
					found = true;
				}
			}
		}
		

				for (int i = 0; i < size; i++){
					mySize.push_back(i);
					sizeLength++;				
				}


				for (int i = 0; i < sizeLength; i++){
					for (int j=0; j<length;j++){
						if (mySize.at(i)==index.at(j)){
						mySize.at(i)=-1;
						}
					}
				}

							for (int i = 0; i < sizeLength; i++){
								cout << mySize.at(i)<< endl;
								cout <<"seperate"<< endl;
				}

	//			unique( mySize.begin(), mySize.end() );
	/*
				for (int i =0; i< sizeLength; i++){
					for (int j=0; j< sizeLength; j++)
						if (mySize.at(i)==mySize.at(i+1)){
							mySize.erase(mySize.begin(),i);
						}
				}

							for (int i = 0; i < sizeLength; i++){
							cout << mySize.at(i)<< endl;
							cout << "after unique" <<endl;
				}


				for (int i=0; i<sizeLength; i++){
					if (mySize.at(i)==-1){
						mySize.erase(mySize.begin(), i);
						sizeLength--;
					}
				}
				for (int i = 0; i < sizeLength; i++){
				cout << mySize.at(i)<< endl;	
				}


		return 0;
	}


			for (int i=0; i < sizeLength; i++){
				multiSet.erase(multiSet.begin()+i);
				size--;
			}			
*/
		inStream.close();

		if (!silent){
			cout << inFileName << " intersetction completed" << endl;
		}
		return 1; 
	}
 

//case 9: test if a given item is in the current multiset
	int MultiSet::findItem(string itemName){
		int i;
		cin >> itemName;

		for (i = 0; i < size; i++){
			if (multiSet[i].getName() == itemName){
				if(!silent){
					cout << "Item " << itemName << " found with count " << multiSet[i].getCount() << endl;
				}
			return i;
			}
		}
	   
		if(!silent){
			cout << "Item " << itemName << " not in set" << endl;
		}
		return -1;
 }


//case 10: add an item to the current set if it is not already in it
	int MultiSet::insertItem(string itemName, int count){
		Object o;
		cin >> itemName;
		cin >> count;

		bool found = false;
		for (int i = 0; i < size; i++){
			if (multiSet[i].getName() == itemName){
				multiSet[i].setCount(multiSet[i].getCount() + count);
				if(!silent){
					cout << "Item " << itemName << " inserted with count " << count << endl;
				}
				found = true;
				return i;
				}
		}

		if ( !found){
			o.setName(itemName);
			o.setCount(count);
			multiSet.push_back(o);
			if (!silent){
				cout << "Item " << itemName << " inserted with count " << count << endl;
			}
			size ++;
		  }
		return 1;
	}


//case 11: remove and item from the current set if it is in it
	int MultiSet::deleteItem(string itemName){
		cin >> itemName;

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
				cout << "Item " << itemName << " not in multiset" << endl;
			}
		return 1;
	}



//case 12:   
	int MultiSet::reduceItem(string itemName, int count){
		cin >> itemName;
		cin >> count;

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
			}
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

		cin >> inFileName;

		inStream.open(inFileName.c_str());        
		if(!inStream.is_open()) {
			if (!silent){
				cerr << "File " << inFileName << " cannot be opened!" << endl;
			}
			return 0;
		}
		if(inStream.fail()) {
			if(!silent){
				cerr << "Error: open operation failed!" << endl;
			}
			return 0;
		}
		while (!inStream.eof()){
			inStream >> tempName;
			o.setName(tempName);
			inStream >> tempCount;
			o.setCount(tempCount);
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
		}

		inStream.close();

		if (!silent){
			cout << "Max completed" << endl;
		}
		return 1;
	}


//case 13: get verbose output
	void verboseOutput(){
		cout << "0 - exit; 1 - input <file>; 2 - union <file>; 3 - subtract <file>;" << endl;
		cout << "4 - difference <file>; 5 - intersect <file>; 6 - reset current set" << endl;
		cout << "7 - write <file>; 8 - print; 9 - find <item>; 10 - insert <item><count>;" << endl;
		cout << "11 - delete <item>; 12 - reduce <item><count>; 13 - verbose; 14 - normal; 15 - silent; 16 - help; 17 - max <file>" << endl;
	}



//case 16: get help information
	const string HELP =
		"=================================================================\n" 
		"Usage: proj2 [-s][-v][-h][-f <filename>]\n"
		"\t-s: silent mode\n"
		"\t-v: verbose mode\n"
		"\t-h: print this help\n"
		"\t-f <filename>: read <filename> into the current set\n"
		"=================================================================\n"
		"The numbered commands are as follows: \n"
		"0. exit\n"
		"1. input file <filename>: open and read a list from a file to the current multiset\n"
		"2. union file <filename>: open and union a multiset from a file with the current multiset\n"
		"3. subtract file <filename>: open and subtract multiset from a file from the current multiset\n"
		"4. difference file <filename>: open and find the difference between a multiset from a file and the current multiset\n"
		"5. intersect file <filename>: open and find the intersection between a multiset from a file and the current multiset\n"
		"6. reset current set to the empty multiset\n"
		"7. output file <filename>: open and write the current multiset to a file\n"
		"8. print current multiset to the console\n"
		"9. find <item name>: test if <item name> is in the current multiset\n"
		"10. insert <item name><count>: add <item name> to the current multiset with number <count> if <item name> is not in the current multiset, or increase <item name>'s number by <count> if it is\n"
		"11. delete <item name>: remove <item name> from the current multset if it is in it\n"
		"12. reduce <item name><count>: reduce the number of <item name> by <count>\n"
		"13. verbose output\n"
		"14. normal output\n"
		"15. silent output\n"
		"16. help\n"
		"17. max\n"
		"=================================================================\n";

	const string SOPT = "-s";
	const string VOPT = "-v";
	const string HOPT = "-h";
	const string FOPT = "-f";

//
	void menu(){
		cout << "0=exit, 1=input file, 2=union file, 3=subtract file, 4=difference file, 5=intersect file," << endl;
		cout << "6=reset, 7=save, 8=print, 9=find item, 10=insert item count, 11=delete item," << endl;
		cout << "12=reduce item count, 13=verbose, 14=normal, 15=silent, 16=help" << endl;
	}


//main function

int main(int argc, char *argv []){

	MultiSet myMultiSet;
    
   	char answer;
	int num;
	string itemName;
	string inFileName;
	int count;

	bool first = true;


	for (int i = 1; i < argc; i++) { 	// parse cmdline args
		if (argv[i][0] == '-'){
			if (argv[i] == SOPT) {
				silent = true;
				verbose = false;
			}else if (argv[i] == VOPT) {
				verbose = true; 
				silent = false;
				verboseOutput();
			}else if (argv[i] == HOPT) {
				cout << HELP << endl;
			}else if (argv[i] == FOPT){
				if (i < argc){
					inFileName = argv[i + 1];
					myMultiSet.inputFile(inFileName);
				}
			}else{
			cerr << "Invalid commandline argument: " << argv[i] << endl;
			}
		}else if(argv[i-1]!=FOPT){
			cerr << "Invalid commandline argument: " << argv[i] << endl;
			return -1;
		}

  }


	while (1){
		if (verbose&&!first){
			verboseOutput();
		}
		first = false;
		if (!silent){
			cout << "> " << flush;
		}
		cin >> num;

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
				verbose = true;
				silent = false;
				break;
			case 14:
                verbose = false;
				silent = false;
				break;
			case 15:
				silent = true;
				verbose = false; 
				break;                   
			case 16:
				cout << HELP << endl;
				break;
			case 17:
				myMultiSet.maxSets();
				break;
			default:
				if (!silent){
				cerr << "Invalid command" << endl;
				}
		}			
    }
   return 1;
}
