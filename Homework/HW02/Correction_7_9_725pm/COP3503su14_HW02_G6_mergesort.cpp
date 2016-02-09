/* HW02_mergeSort.cpp
 * Authors:Group 6 (Alxander Geoffroy, Cory Turco, Eric Balingit, Wenlan Tian)
 * Date:07-08-2014
 */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "COP3503su14_HW02_G6_mergesort.h"

using namespace std;

vector<int> merge(vector<int> &left, vector<int> &right){
	vector<int> v;

	unsigned int l =0;
	unsigned int r =0;

	//Both of two vectors are not empty
	while(left.size() > l && right.size()>r){
		if(left[l]<=right[r]){
			v.push_back(left[l++]);
		}else{
			v.push_back(right[r++]);
		}
	}

	//left vector is empty, put all the remaining elements in right vector to v
	while(right.size() > r && left.size()==l){
		v.push_back(right[r++]);
	}

	//right vector is empty, put all the remaining elements in left vector to v
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
		for (unsigned int j = mid+1; j< data.size(); j++){
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


