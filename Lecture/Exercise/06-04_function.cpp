#include <iostream>
using namespace std;

int max(int a, int b);
int min(int a, int b);
int sum(int a, int b);


int main(){
	int i, j;
	int X, Y;
    cout <<"Please enter the first number: " << flush;
	cin >> i;
	cout <<"Please enter the second number: " << flush;
	cin >> j;
	max (i,j);
	min (i,j);
	cout << "The maximum number between " << i << " and " << j << " is " << max (i,j) << endl;
	cout << "The minimum number between " << i << " and " << j << " is " << min (i,j) << endl;

	cout <<"Please enter X: " << flush;
	cin >> X;
	cout <<"Please enter Y: " << flush;
	cin >> Y;
	sum (X,Y);
    cout << "The sum of " << X << " and " << Y << " is " << sum (X,Y) << endl;

	return 0;

}

int max(int a, int b)
{
    int maxval;

    if (a > b) maxval = a;
    else maxval = b;
  
    return maxval;
}

int min(int a, int b)
{
	int minval;
    
	if (a < b) minval =a;
	else minval = b;

	return minval;
  
}


int sum(int a, int b)
{
  int sum = 0;

  for (int i = a; i <= b; ++i)
    sum += i;
  
  return sum;
}


