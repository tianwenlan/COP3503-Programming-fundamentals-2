#include <iostream>
using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 2;
	int b = 3;
    cout << "Before swap,a= " << a << endl;
	cout << "Before swap,b= " << b << endl;
	swap(a, b);
	cout << "After swap,a= " << a << endl;
	cout << "After swap,b= " << b << endl;
}


