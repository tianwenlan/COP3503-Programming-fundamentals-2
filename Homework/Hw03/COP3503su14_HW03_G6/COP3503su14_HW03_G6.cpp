/* HW03_hanoi.cpp
 * Authors:Group 6 (Alxander Geoffroy, Cory Turco, Wenlan Tian)
 * Date:07-25-2014
 *
 *
 * compile: make -f makefile
 * command: ./hanoi
 * option: -s (show every step)
 * enter "0" to finish enter rings
 * */

#include <iostream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;


struct Point{
	int x;
	double y;
};

vector<int> A;
vector<int> B;
vector<int> C;

string source = "tower0";
string spare = "tower1";
string destination = "tower2";

bool silent = true;

void print(){
	cout <<"Tower 0: " << flush;
	for (int i=0; i< A.size();i++){
	cout << A[i] << " " <<flush;
	}

	cout << endl;

	cout <<"Tower 1: " << flush;

	for (int i=0; i< B.size();i++){
		cout << B[i] << " " <<flush;
	}
	cout << endl;

	cout << "Tower 2: " << flush;

	for (int i=0; i< C.size();i++){
		cout << C[i] << " " <<flush;
	}
	cout << endl;
	cout << "=======================" << endl;

}


void hanoi(int n, string &src, string &spr, string &dst){

	if(n>1){
		hanoi(n-1, src, dst, spr);
	}

	if (src == "tower0" && dst == "tower2"){
		C.push_back(n);
		A.pop_back();
	}else if(src == "tower0" && dst == "tower1"){

		B.push_back(n);
		A.pop_back();
	
	}else if(src == "tower1" && dst == "tower2"){

		C.push_back(n);
		B.pop_back();

	}else if(src == "tower1" && dst == "tower0"){
		A.push_back(n);
		B.pop_back();

	}else if(src == "tower2" && dst == "tower0"){
		A.push_back(n);
		C.pop_back();

	}else if(src == "tower2" && dst == "tower1"){
		B.push_back(n);
		C.pop_back();
	}

	if(!silent){
		print();
	}


	if(n>1)
	{
		hanoi(n-1, spr, src, dst);
	}
	
}
	
	void menu(){
		cout << "====================================================================================" << endl;
		cout << "\t0-exit" << endl;
		cout << "\t1-Show the time to solve the tower of Hanoi problem with differnt number of disks" << endl;
		cout << "\t2-Draw the graph time vs. number of disks" << endl; 
		cout << "\t3-Display the contents of all three towers every time a disk is moved " << endl;
		cout << "\t  (commands [./hanoi -s] at the beginning also display the contents of every step)" << endl;
		cout << "\t4-Unshown the contents of every step" << endl;
		cout << "\t5-Show menu" << endl;
		cout << "====================================================================================" << endl;
	}
	


	const string SOPT = "-s";

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

void printGraph(vector<Point> points){

	//print the y-axis
	//print the largest N to the fixed position (60,y)
	cout << "y(time)\n^\n|\n|\n|" << flush;
	
	for (int i = 1; i < 60; i++){
		cout << " " << flush;
	}
		cout << "*" << endl;
	
	for (int i =points.size()-2; i>=0; i--){
		for (int iy =0; iy< (int)(30*(points[i+1].y-points[i].y)/(points[points.size()-1].y-points[0].y)); iy++){
				cout << "|" << endl;
		}

		cout << "|" << flush;

		for (int ix = 1; ix < (int)(60*points[i].x/points[points.size()-1].x);ix++){

			cout << " " << flush;
		}
			cout << "*" << endl;
	}

		cout << "|" << endl;

		//print the x axis
	for (int i = 0; i < 70 ;i++){
		cout << "-" << flush;
	}

	cout << "> x(number of disks)" << endl;

}



//main function
int main(int argc, char *argv []){
	cout << "------------------------------------------------------------------------------------" << endl;
	cout << "\tThis is a program to solve the Towers of Hanoi problem.\n"
		 << "\tYou can enter different numbers of disks to play with."
		 << endl;

	menu();



	for (int i =1; i< argc; i++){
		if(argv[i]==SOPT){
			silent = false;
			cout << "Content of every step will be shown!" << endl;
		}
	}

	int num =0 ;
	int n =0;
	vector<Point> points;
	Point point;


	while(1){
		cout << "> " << flush;
		 
		cin >> num;

		while (cin.fail()){
			cin.clear();
			cin.ignore();
			cerr << "Not a valid number. Please reenter a number: ";
			cin >> num;
		}

		switch(num){
			case 0:
				cout << "Byebye~" << endl;
				return 0;
			case 1:

				cin.clear();
				cin.ignore();

				points.clear();

				while(cin){

					clock_t begin, end;
					double time_spent;

					A.clear();
					B.clear();
					C.clear();

					cout << "please enter the number of disks you want to play (integer >0): " << endl;
					cout << "(enter[0] to finish input)" << endl;

					cin >> n;
					point.x=n;

					if(n==0){
						break;
					}

					for(int i =n; i>0; i--){
						A.push_back(i);
					}

					//time before hanoi
					begin = clock();

					hanoi(n, source, spare, destination);

					//time after hanoi
					end = clock();

					//time spent for hanoi
					time_spent = (double)(end - begin)/CLOCKS_PER_SEC;

					point.y = time_spent;
	
					points.push_back(point);

					cout << "[" << n << "]disks took " << time_spent << " seconds"<< endl;

				}

				break;

			case 2:
				if(points.size()>0){
					vector<int> tempX;
					vector<Point> tempPoints;
				

					for (int i =0; i < points.size(); i++){
						tempX.push_back(points[i].x);
					}

					//sort the input points by x
					tempX = mergeSort(tempX);
				
					for(int i =0; i<tempX.size(); i++){
						for(int j =0; j<points.size();j++){
							if(tempX[i]==points[j].x){
								tempPoints.push_back(points[j]);
							}
						}
					}

					//test points after sorting
			//		for(int i =0; i< tempPoints.size(); i++){
			//			cout << tempPoints[i].x << " " << tempPoints[i].y << endl;
			//		}

					//print points
					printGraph(tempPoints);
		
				}else{
					cout << "No points stored" << endl;
					cout << "Please use command 1 to input points(number of disks, time)" << endl;
				}

				break;
			case 3:

				silent = false;

				while(cin){

					A.clear();
					B.clear();
					C.clear();

					cout << "please enter the number of disks you want to play (integer >0): " << endl;
					cout << "enter [0] to end input" << endl;

					cin >> n;

					if(n==0){
						break;
					}

					for(int i =n; i>0; i--){
						A.push_back(i);
					}

					//print the original towers
					print();

					hanoi(n, source, spare, destination);
				}

				break;

			case 4:
				silent = true;
				cout << "Content of every step will NOT be shown!" << endl;
				break;
			case 5:
				menu();
				break;
			default:
				cerr << "Invalid command" << endl;

		}

	}

}

