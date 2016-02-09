#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

/////////method declarations////////////////////////////////////
void input_file(string, vector<int>&);
void merge_sort(vector<int>&);
vector<int> merge(vector<int>&, vector<int>&);
////////////////////////////////////////////////////////////////
//////////////////file insertion////////////////////////////////
void input_file(string filename, vector<int>& input){
	ifstream file(filename.c_str());		//<fstream>
	vector<string> temp; 
	string line;
	if (file.is_open()) {             
		while(getline(file,line)) {
			istringstream ss(line);			//<sstream>
			while(!ss.eof()){
				string x;
				getline(ss,x,' ');
				temp.push_back(x);
			}
		}
		file.close();
	}
	//converts the strings of temp into integers for input
	for (int i = 0; i < temp.size(); i++){
		int x;
		x = atoi(temp[i].c_str());  //<cstdlib>
		input.push_back(x);
	}
}


void output_file(string outFilename, vector<int> &input){
		ofstream outputFile;

		output.open(outFileName.c_str()); 
		if (output.fail()){
			cerr << "File " << outFileName << " cannot be opened" << endl;
		}

	for (int i=0; i< input.size(); i++)
	{
		outputFile << input[i] << endl;
	}

}
////////////////////////////////////////////////////////////////
///////////////recursive////////////////////////////////////////
void merge_sort(vector<int>& input){
	//base 1
	if (input.size() == 1){}
	//recursion
	else {
		//first half of input array
		vector<int> temp1(input.begin(), input.begin() + input.size()/2);
		//second half of input array
		vector<int> temp2(input.begin() + input.size()/2, input.end());
		merge_sort(temp1);
		merge_sort(temp2);
		input = merge(temp1, temp2);
	}
}

//helper function
vector<int> merge(vector<int>& temp1, vector<int>& temp2){
	bool cont = true;
	int x = 0;
	int y = 0;
	vector<int> out;
	while (cont) {
		if (x == temp1.size()){
			if (y != temp2.size()){
				out.push_back(temp2[y]);
				y++;
			}
			else {
				cont = false;
			}
		}
		else if (y == temp2.size()){
			if (x != temp2.size()){
				out.push_back(temp1[x]);
				x++;
			}
			else {
				cont = false;
			}
		}
		else {
			if (temp1[x] > temp2[y]){
				out.push_back(temp2[y]);
				y++; 
			}
			else {
				out.push_back(temp1[x]);
				x++;
			}
		}
	}
	return out;

}
////////////////////////////////////////////////////////////////
//////////////////////main//////////////////////////////////////
int main() {
	vector<int> input;
	vector<int> output;
	string filename;
	string outFileName;
	cout << "Filename: ";
	cin >> filename;
	input_file(filename, input);
	merge_sort(input);

/////////////testing////////////////////////////
////////////////////////////////////////////////
	output_file(outFileName, input);

}

////////////////////////////////////////////////////////////////

