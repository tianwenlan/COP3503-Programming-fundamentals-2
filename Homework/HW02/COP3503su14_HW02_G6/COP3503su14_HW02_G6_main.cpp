/* HW02_mergeSort
 * Authors:Group 6 (Alxander Geoffroy, Cory Turco, Eric Balingit, Wenlan Tian)
 * Date:07-09-2014
 *
 *
 * Command: 
 * mergesort unsortedlist.txt sortedlist.txt
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "COP3503su14_HW02_G6_mergesort.h"
#include "COP3503su14_HW02_G6_data.h"


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
