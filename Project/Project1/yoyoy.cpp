#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//Prototypes of the methods 
void printPrompt();
void inputFile(string, vector<string> &);
void unionFile(string, vector<string> &);
void subtractFile(string, vector<string> &);
void differenceFile(string, vector<string> &);
void intersectFile(string, vector<string> &);
void outputFile(string, vector<string>);
void find(string, vector<string>);
void insert(string, vector<string> &);
void deleteItem(string, vector<string> &);
bool verbose = true;
bool silent = false;
void printVerbosePrompt();

int main()
{
	int choice;
	vector<string> set;
	string fileName, item;
	printPrompt();
	bool first = true;
	do{
		if (verbose&&!first){
			printVerbosePrompt();
		}
		first = false;
		if (!silent){ cout << ">"; }
		cin >> choice;
		if (choice == 1){
			if (!silent)
				cout << "Enter File Name" << endl;
			if (!silent)
				cout << ">";
			cin >> fileName;
			inputFile(fileName, set);
		}
		else if (choice == 2){
			if (!silent)
				cout << "Enter File Name" << endl;
			if (!silent)
				cout << ">";
			cin >> fileName;
			unionFile(fileName, set);
		}
		else if (choice == 3){
			if (!silent)
				cout << "Enter File Name" << endl;
			if (!silent)
				cout << ">";
			cin >> fileName;
			subtractFile(fileName, set);
		}
		else if (choice == 4){
			if (!silent)
				cout << "Enter File Name" << endl;
			if (!silent){ cout << ">"; }
			cin >> fileName;
			differenceFile(fileName, set);
		}
		else if (choice == 5){
			if (!silent)
				cout << "Enter File Name" << endl;
			if (!silent){ cout << ">"; }
			cin >> fileName;
			intersectFile(fileName, set);
		}
		else if (choice == 6){
			set.clear();
			if (!silent)
				cout << "Reset Completed" << endl;
		}
		else if (choice == 7){
			if (!silent)
				cout << "Enter Output File Name" << endl;
			if (!silent){ cout << ">"; }
			cin >> fileName;
			outputFile(fileName, set);
		}
		else if (choice == 8){
			for (int i = 0; i < set.size(); i++){
				cout << set.at(i) << endl;
			}
		}
		else if (choice == 9){
			if (!silent)
				cout << "Enter Item to Find" << endl;
			if (!silent){ cout << ">"; }
			cin >> item;
			find(item, set);
		}
		else if (choice == 10){
			if (!silent)
				cout << "Enter Item to Insert" << endl;
			if (!silent){ cout << ">"; }
			cin >> item;
			insert(item, set);
		}
		else if (choice == 11){
			if (!silent)
				cout << "Enter Item to Delete" << endl;
			if (!silent){ cout << ">"; }
			cin >> item;
			deleteItem(item, set);
		}
		else if (choice == 12){
			verbose = true;
			silent = false;
		}
		else if (choice == 13){
			verbose = false;
			silent = false;
		}
		else if (choice == 14){
			silent = true;
			verbose = false;
		}
		else if (choice == 15){
			cout << "This program requires that you use .txt files" << endl;
			cout << "Press the number you want as input" << endl;
			cout << "then press enter and enter the required the info" << endl;
			cout << "The prompt tells what you need for info" << endl;
		}
		else if (choice != 0){
			if (!silent)
				cout << "Command is invalid" << endl;
		}

	} while (choice != 0);
}

//Prints the prompt 
void printPrompt(){
	cout << "0: Exit" << endl;
	cout << "1: Input File <filename>: open and read a list from a file to the current list" << endl;
	cout << "2: Union File <filename>: open and union a set from a file with the current set" << endl;
	cout << "3: Subtract File <filename>: open and subtract set from a file from the current set" << endl;
	cout << "4: Difference File <filename>: open and find the difference between a set from a file and the current set" << endl;
	cout << "5: Intersect File <filename>: open and find the intersection between a set from a file and the current set" << endl;
	cout << "6: Reset current set to the empty set" << endl;
	cout << "7: Output File <filename>: open and write the current set to a file" << endl;
	cout << "8: Print Current Set to the console" << endl;
	cout << "9: Find Item <item name>: test if <item name> is in the current set" << endl;
	cout << "10: Insert Item <item name>: add <item name> to the current set if it is not already in it" << endl;
	cout << "11: Delete Item <item name>: remove <item name> from the current set if it is in it" << endl;
	cout << "12: Verbose Output" << endl;
	cout << "13: Normal Output" << endl;
	cout << "14: Silent Output" << endl;
	cout << "15: Help" << endl;
}

//choice 1: takes in a file and makes it the new set
void inputFile(string fileName, vector<string> &temp){
	ifstream input;
	string tempString;

	temp.clear();
	input.open(fileName.c_str());
	if (input.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}
	while (!input.eof())
	{
		input >> tempString;
		if (tempString.length() > 0){
			temp.push_back(tempString);
		}

		tempString.clear();
	}
	if (!silent)
		cout << "New set loaded" << endl;
	cout << endl;
}

//choice 2: takes in a file and adds it to the current set. no repeats
void unionFile(string fileName, vector<string> &temp){
	ifstream input;
	string tempString;
	bool found = false;

	input.open(fileName.c_str());
	if (input.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}
	while (!input.eof()){
		input >> tempString;
		if (tempString.length() > 0){
			for (int i = 0; i < temp.size(); i++){
				if (tempString == temp.at(i)){
					found = true;
				}
			}
			if (!found){
				temp.push_back(tempString);
			}
			found = false;
		}
		tempString.clear();
	}
	if (!silent)
		cout << "Union completed" << endl;
	cout << endl;
}

//choice 3: takes in a file and removes all occurences of that file from the current set
void subtractFile(string fileName, vector<string> &temp){
	ifstream input;
	string tempString;

	input.open(fileName.c_str());
	if (input.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}
	while (!input.eof()){
		input >> tempString;
		if (tempString.length() > 0){
			for (int i = 0; i < temp.size(); i++){
				if (tempString == temp.at(i)){
					temp.erase(temp.begin() + i);
				}
			}
		}
	}
	if (!silent)
		cout << "Subtraction completed" << endl;
	cout << endl;
}

//choice 4: unionFile - intersectFile is the differenceFile, that is the logic used
void differenceFile(string fileName, vector<string> &temp){
	ifstream input;
	string tempString;
	vector <string> unionset, intersectset, b;
	bool found = false;

	input.open(fileName.c_str());
	if (input.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}
	while (!input.eof()){
		input >> tempString;
		if (tempString.length() > 0){
			b.push_back(tempString);
		}
	}

	unionset = temp;
	intersectset = temp;

	unionFile(fileName, unionset);
	intersectFile(fileName, intersectset);
	int i = 0;
	while (i < unionset.size()){
		for (int j = 0; j < intersectset.size(); j++){
			if (unionset.at(i) == intersectset.at(j)){
				unionset.erase(unionset.begin() + i);
				found = true;
			}
		}
		if (found){
			i--;
			found = false;
		}
		i++;
	}
	temp = unionset;
}

//choice 5: takes in a file and makes the current set equal to only the current occurences
void intersectFile(string fileName, vector<string> &temp){
	ifstream input;
	string tempString;
	vector<string> newset;
	bool found = false;

	input.open(fileName.c_str());
	if (input.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}
	while (!input.eof()){
		input >> tempString;
		if (tempString.length() > 0){
			for (int i = 0; i < temp.size(); i++){
				if (tempString == temp.at(i)){
					found = true;
				}
			}
			if (found){
				newset.push_back(tempString);
			}
			found = false;
		}
	}
	if (!silent)
		cout << "Intersection completed" << endl;
	temp = newset;
	cout << endl;
}

//choice 6: takes in a output file name and creates the output file with the current set
void outputFile(string fileName, vector<string> temp){
	ofstream output;

	output.open(fileName.c_str());
	if (output.fail()){
		if (!silent)
			cout << "File " << fileName << " cannot be opened" << endl;
		return;
	}

	for (int i = 0; i < temp.size(); i++){
		output << temp.at(i) << endl;
	}
	if (!silent)
		cout << "Save to " << fileName << " completed" << endl;

}

//choice 7: finds the item, if there
void find(string item, vector<string> temp){
	for (int i = 0; i < temp.size(); i++){
		if (item == temp.at(i)){
			if (!silent)
				cout << "Item " << item << " found" << endl;
			return;
		}
	}
	if (!silent)
		cout << "Item " << item << " not found" << endl;
}

//choice 8: inserts the item, if not there
void insert(string item, vector<string> &temp){
	bool found = false;
	for (int i = 0; i < temp.size(); i++){
		if (item == temp.at(i)){
			found = true;
			if (!silent)
				cout << "Item " << item << " already in set" << endl;
			return;
		}
	}

	if (!found){
		temp.push_back(item);
		if (!silent)
			cout << "Item " << item << " inserted" << endl;
	}
}

//choice 9: delets the item, if there
void deleteItem(string item, vector<string> &temp){
	for (int i = 0; i < temp.size(); i++){
		if (item == temp.at(i)){
			temp.erase(temp.begin() + i);
			if (!silent)
				cout << "Item " << item << " deleted" << endl;
			return;
		}
	}
	if (!silent)
		cout << "Item " << item << " not in set" << endl;
}

//choice 12: the verbose the prompt
void printVerbosePrompt(){
	cout << "0 - Exit; 1 - Input <file>; 2 - Union <file>; 3 - Subtract <file>;" << endl;
	cout << "4 - Difference <file>; 5 - Intersect <file>; 6 - Reset Current Set;" << endl;
	cout << "7 - Write <file>; 8 - Print; 9 - Find <item>; 10 - Insert <item>;" << endl;
	cout << "11 - Delete <item>; 12 - Verbose; 13 - Normal; 14 - Silent; 15 - Help" << endl;
}
