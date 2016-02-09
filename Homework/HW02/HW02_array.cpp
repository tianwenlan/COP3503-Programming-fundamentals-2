/* HW02_mergeSort.cpp
 * Author: Wenlan Tian
 * Date:07-08-2014
 */

#include <iostream>
#include <string>

using namespace std;

void merge(int arr[], int begin, int end){
	int size = (end - begin )+1;
	int *temp = new int [size]();

	int i = begin;
	int mid = (begin + end)/2;
	int t=0;
	int j=mid+1;


	while(t<size)
	{
		if((i<=mid && arr[i]<=arr[j])|| j>end){
			temp[t++] = arr[i++];
		}else{
			temp[t++] = arr[j++];
		}
	}

	for (int k=0; k<size;k++){
		cout << "temp: " << temp[k] << endl;
	}


	for(t=0;t<size;t++){
		arr[begin+t] = temp[t];
	}

	delete temp;

	}

void mergeSort(int arr[], int begin, int end ){
	int mid;
	if(begin < end){
		//divide the original array to half
		mid = (begin + end)/2;
		
		//the firt half array
		mergeSort(arr, begin, mid);

		//the second half array
		mergeSort(arr, mid+1, end);
		
		merge(arr, begin, end);
	}
	
}


//main function
int main(){

	int num;

	//test array with even elements

	int a[] = {13,32,77,55,43,1,42,88};

	num=sizeof(a)/sizeof(int);

	mergeSort(a, 0, num-1);

	cout << "Sorted a[]: " << flush;

	for (int i=0; i< num; i++)
	{
		cout << a[i] << " " << flush;
	}

	cout << endl;


	//test array with odd elements

	int b[] = {13,32,77,55,43,1,42,88,5};
	
	num=sizeof(b)/sizeof(int);

	mergeSort(b, 0, num-1);

	cout << "Sorted b[]: " << flush;

	for (int i=0; i< num; i++)
	{
		cout << b[i] << " " << flush;
	}

	cout << endl;

}
