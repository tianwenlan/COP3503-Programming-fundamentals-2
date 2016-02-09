/* HW02_mergeSort.cpp
 * Authors:Group 6 (Alxander Geoffroy, Cory Turco, Eric Balingit, Wenlan Tian)
 * Date:07-08-2014
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "COP3503su14_HW02_G6_data.h"

using namespace std;

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


