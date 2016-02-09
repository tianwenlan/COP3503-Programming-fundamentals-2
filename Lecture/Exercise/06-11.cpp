#include <iostream>
using namespace std;

class Fraction
{
	private:
		int numerator;
		int denominator;

	public:
		Fraction ();
		Fraction (int, int);
		Fraction* add(Fraction &);
		int getNum();
		int getDen();
		void setNum(int);
	    void setDen(int);
};

int main()
{
	int i,j;
	Fraction f1,f2;
	cout << "Please enter the numerator: " << flush;
	cin >> i;
	cout << "Please enter the denominator: "<< flush;
	cin >> j;
	f1.setNum(i);
	f1.setDen(j);


    cout << "Fraction is: " << flush;
	cout << f1.getNum() << "/";
	cout << f1.getDen() << endl;
    
	Fraction* fp3=f1.add(f2);
	cout << fp3->getNum()<< "/";
	cout << fp3->getDen()<< endl;

	return 0;

}


int Fraction::getNum(){
	return this -> numerator;
}

int Fraction::getDen(){
	return this -> denominator;
}

void Fraction::setNum(int numerator){
	this -> numerator = numerator;
}

void Fraction::setDen(int denominator){
	this -> denominator = denominator;
}

Fraction::Fraction(){
}

Fraction::Fraction(int numerator, int denominator){
}

Fraction* Fraction::add(Fraction &f)
{
	int num = numerator * f.denominator;
	num += f.numerator * denominator;
	int dnm = f.denominator * denominator;

	return new Fraction(num, dnm);
}



