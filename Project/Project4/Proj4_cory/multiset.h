#ifndef MULTISET_0331
#define MULTISET_0331

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T> class Multiset : public Set<T>{
	private:
		vector<double> count;
						
	public:
		Multiset();
		void reset();
		void print();
		void insert_item(T, double);
		bool delete_item(T);
		int reduce_item(T, double);
		double item_count(T);
		double get_count(int);
		const Multiset operator+(const Multiset &) const;  //union
		const Multiset operator-(const Multiset &) const;  //subtraction
		const Multiset operator*(const Multiset &) const;  //intersect
		const Multiset operator^(const Multiset &) const;  //difference

		Multiset & operator=(const Multiset &);  //deep copy
		Multiset & operator==(const Multiset &);  //equality
		Multiset & operator<(const Multiset &);  //proper subset
		Multiset & operator<=(const Multiset &);  //subset

		friend ostream & operator<<(ostream &, const Multiset);  //stream out
		friend istream & operator>>(istream &, const Multiset);  //stream in

};

class Recipe {
	private:
		string title;
		Multiset<string> ingredients;
		string instructions;
		Multiset<string> equipment;
	public:
		Recipe(string);
		void add_ingredient(string, double);
		void add_instruction(string);
		void add_equipment(string, int);
		string get_title();
		string get_instruction();
		Multiset<string> get_ingredients();
		Multiset<string> get_equipment(i;

};

#endif
