#ifndef PROJ4_H
#define PROJ4_H
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

template <class T> class MySet;
template <class T> ostream& operator<<(ostream&, const MySet<T>);
template <class T> istream& operator>>(istream&, MySet<T> &);
template <class T> int operator==(const MySet<T> &, const MySet<T> &);
template <class T> int operator<(const MySet<T> &, const MySet<T> &);  //proper subset


template <class T> class MySet{
	protected:
		vector<T> current;
		unsigned int location;
	public:
		friend ostream & operator<< <>(ostream &, const MySet<T>);  //stream out
		friend istream & operator>> <>(istream &, MySet<T> &);  //stream in
		friend int operator==<> (const MySet<T> &, const MySet<T> &);  //equality
		friend int operator< <>(const MySet<T> &, const MySet<T> &);  //proper subset

		MySet();
		void clear();
		void print();
		bool find(T);
		void addElt(T);
		bool deleteElt(T);
		T get_name(int);
		int size();
		int get_location();
		void output(string, MySet<T> &);
		bool readSet(MySet<T> &);
		void workWithSets(T &, string &);

		int compare(MySet<T> &);

		MySet<T> operator+(const MySet<T> &) const;  //union
		MySet<T> operator-(const MySet<T> &) const;  //subtraction
		MySet<T> operator*(const MySet<T> &) const;  //intersect
		MySet<T> operator^(const MySet<T> &) const;  //difference
/*
		MySet<T> operator+=(const MySet<T> &);  //union
		MySet<T> operator-=(const MySet<T> &);  //subtraction
		MySet<T> operator*=(const MySet<T> &);  //intersect
		MySet<T> operator^=(const MySet<T> &);  //difference
		int & operator<=(const MySet<T> &);  //subset

*/
		MySet<T> & operator=(const MySet<T> &);  //deep copy

		bool silent=false;
		bool verbose=false;


};

#endif
