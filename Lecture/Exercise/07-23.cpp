#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

using namespace std;

class Fraction {
	private:
	int numerator;
	int denominator;
	static int gcd(int n, int d);
	

	public:
	int getNum();
	void setNum(int);
	int getDenom();
	void setDenom(int);
	Fraction(int, int);
	Fraction();
	Fraction(int n);  // conversion from int	
	Fraction add(const Fraction &f) const;
	Fraction subtract(const Fraction &f) const;
	Fraction multiply(const Fraction &f) const;
	Fraction divide(const Fraction &f) const;
	// comparison methods
	int compare(const Fraction &f) const;
	bool equals(const Fraction &f) const;
	// conversion methods
	int intValue() const;
	double doubleValue() const;
	string toString() const;
	bool operator<(const Fraction& f) const;
	bool operator==(const Fraction& f) const;
	
};

int Fraction::getNum(){
	return this->numerator;
}

void Fraction::setNum(int num){
	this->numerator = num;
}

int Fraction::getDenom(){
	return this->denominator;
}

void Fraction::setDenom(int dnm){
	this->denominator = dnm;
}

Fraction::Fraction() :
numerator(0), denominator(1) {}

Fraction::Fraction(int n, int d) {
	int g = gcd(n, d);
	if (g > 1)   {
		n /= g;
		d /= g;
	}
	numerator = n;
	denominator = d;
}

Fraction::Fraction(int n){
	numerator = n;
	denominator = 1;
}


Fraction Fraction::add(const Fraction &f) const{
  int num = this->numerator * f.denominator;
  num += f.numerator * this->denominator;
  int dnm = f.denominator * denominator;

  return Fraction(num, dnm);
}

Fraction Fraction::subtract(const Fraction &f) const{
  int num = this->numerator * f.denominator;
  num -= f.numerator * this->denominator;
  int dnm = f.denominator * denominator;

  return Fraction(num, dnm);
}

Fraction Fraction::multiply(const Fraction &f) const{
  int num = this->numerator * f.numerator;
  int dnm = this->denominator * f.denominator;

  return Fraction(num, dnm);
}

Fraction Fraction::divide(const Fraction &f) const{  // divide is multiply by reciprocal
  int num = this->numerator * f.denominator;
  int dnm = this->denominator * f.numerator;

  return Fraction(num, dnm);
}

int Fraction::compare(const Fraction &f) const{
  Fraction temp = subtract(f); // difference
  int num = temp.getNum();
  if (num < 0) return -1;    // neg => smaller
  return (num > 0 ? 1 : 0);  // pos => bigger
}

bool Fraction::equals(const Fraction &f) const{
	return(0 == compare(f));
}

int Fraction::intValue() const{
	return (numerator)/(denominator);
}

double Fraction::doubleValue() const{
	return ((double) numerator )/((double) denominator);
}

string Fraction::toString() const{
	stringstream ss;
	ss << numerator;
	if (denominator > 1 && numerator != 0)
		ss << "/" << denominator;
	return (ss.str());
}

bool Fraction::operator<(const Fraction& f) const{
	return (compare(f) < 0);
}

bool Fraction::operator==(const Fraction& f) const{
	return (compare(f) == 0);
}


int main() {
	int i;
	int j;
	Fraction g1;

	cout << "Enter two integers: " << flush;
	cin >> i >> j;
	g1.setNum(i);    // test setters
	g1.setDenom(j);

	cout << "Enter two integers: " << flush;
	cin >> i >> j;
	Fraction g2(i,j);  // test list constructor

	// test toString
	// test add

	cout << g1.toString() << " plus " << g2.toString() << " equals " << g1.add(g2).toString() << endl;

	cout << g1.toString() << " compare " << g2.toString() << " is " << g1.compare(g2) << endl;

    cout << g1.toString() << " equals " << g2.toString() << " is " <<  g1.equals(g2) << endl;

	// test overloading < operator
	cout << g1.toString() << " < " << g2.toString() << " is " << (g1 < g2) << endl;
    
	// now test auto conversion from int
	cout << g1.toString() << " plus 1 equals " << g1.add(1).toString() << endl;
	

	return 0;  // done for now!
}


  

