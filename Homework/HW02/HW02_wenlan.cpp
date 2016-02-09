/* HW02_mergeSort.cpp
 * Authors:Group 6 (Alxander Geoffroy, Cory Turco, Eric Balingit, Wenlan Tian)
 * Date:07-08-2014
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

vector <int> merge (vector <int> &, vector <int> &);
vector <int> merge_sort (vector <int> &);
void inputFile(string, vector <int>&);
void ouputFile(string, vector <int>);
void print(vector <int>);


vector<int> merge(vector<int> &left, vector<int> &right){
	vector<int> v;

	int l =0;
	int r =0;

	while(left.size() > l && right.size()>r){
		if(left[l]<=right[r]){
			v.push_back(left[l++]);
		}else{
			v.push_back(right[r++]);
		}
	}

	while(right.size() > r && left.size()==l){
		v.push_back(right[r++]);
	}
	
	while(left.size() > l && right.size() == r){
		v.push_back(left[l++]);
	}

	return v;
}


vector<int> mergeSort(vector<int> &data){
	vector <int> left;
	vector <int> right;
	vector <int> v;

	if(data.size() <= 1){
		return data;
	}else{
		int mid = ((data.size())/2-1);

		//divide the original array to half

		//put the first half elements to left vector
		for(int i = 0; i<=mid; i++){
			left.push_back(data[i]);
		}

		//put the second half elements to right vector
		for (int j = mid+1; j< data.size(); j++){
			right.push_back(data[j]);
		}
		
		//the firt half array
		left = mergeSort(left);

		//the second half array
		right = mergeSort(right);
		
		v = merge(left, right);
	}

	return v;
	
}

void inputFile(string inFileName, vector<int> &input){

	int num=0;
	ifstream inStream;

	inStream.open(inFileName.c_str());

	if(inStream.fail()){
		cerr << "Unable to open file: " << inFileName << endl;
	}

	while (inStream >> num){
		input.push_back(num);
	}

	inStream.close();
}

void outputFile(string outFileName, vector<int> output){
	ofstream outfile;

	outfile.open(outFileName.c_str()); 
	if (outfile.fail()){
		cerr << "File " << outFileName << " cannot be opened" << endl;
	}

	for (int i=0; i< output.size(); i++)
	{
		outfile << output[i] << endl;
	}

}

void print(vector<int> file){

	cout << "{";

	for (int i=0; i< file.size()-1; i++)
	{
		cout << file[i] << "," << flush;
	}
	cout << file[file.size()-1] << "}" << endl;

}


//main function
int main(int argc, char *argv []){

	string inFileName;
	string outFileName;
	vector<int> a;

	inFileName = argv[1];
	outFileName = argv[2];

	//Input the original vector
	inputFile(inFileName, a);

	//Print the original vector to prompt
	cout << "Unsorted vector = ";
	print(a);

	//Sort the vector
	a = mergeSort(a);
	cout << "Sort completed!" << endl;

	//Output the sorted vector to file
	outputFile(outFileName,a);

	//Output the sorted vector to prompt
	cout << "Sorted vector = ";
	print(a);

}
