#ifndef MULTISET_0331
#define MULTISET_0331

#include "MySet.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/////////////////CLASS/////////////////////////////////////////

template<class T> class Multiset : public MySet<T>{
	private:
		vector<double> count;
		int min(int, int);	//helper
		int abs(int, int); //helper
		void resize(int); //helper
						
	public:
		Multiset();
		void clear();
		void print() const;
		void addElt(T, double);
		bool deleteElt(T);
		int reduceElt(T, double);
		double item_count(T);
		double get_count(int) const;


		Multiset<T> operator+ (const Multiset<T> & rhs);	//union
		Multiset<T> operator- (const Multiset<T> & rhs);	//subtract
		Multiset<T> operator* (const Multiset<T> & rhs);		//intersect
		Multiset<T> operator^ (Multiset<T> & rhs);		//difference
		Multiset<T> & operator= (const Multiset<T> & rhs);	//deep copy
		Multiset<T> & operator+= (const Multiset<T> & rhs);	//set to union
		Multiset<T> & operator-= (const Multiset<T> & rhs);	//set to subtract
		Multiset<T> & operator*= (const Multiset<T> & rhs);	//set to intersect
		Multiset<T> & operator^= (Multiset<T> & rhs);	//set to difference
		bool operator== (const Multiset<T> & rhs) const;	//equality
		bool operator< (const Multiset<T> & rhs) const; 	//proper subset
		bool operator<= (const Multiset<T> & rhs) const;	//subset
		template<class Y> friend ostream & operator<< (ostream & os, const Multiset<Y> & rhs);	//stream out
		template<class Y> friend istream & operator>> (istream & os, const Multiset<Y> & rhs); //stream in
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
		Multiset<string> get_equipment();
};
////////////////////////////////////////////////////////////

//////////////////IMPLEMENTATION///////////////////////////

template <class T> Multiset<T>::Multiset() {
};

template <class T> void Multiset<T>::clear() {
	this->current.clear();
	this->current.resize(10);
	count.clear();
	count.resize(10);
};

template <class T> void Multiset<T>::print() const{
	for (int i = 0; i < this->current.size(); i++){
		cout << count[i] << " " << this->current[i] << endl;
	}
};

template <class T> void Multiset<T>::addElt(T item, double num){
	if (this->find_item(item)){
		count[this->location] += num;
	} else{
		this->current.push_back(item);
		count.push_back(num);
	}
};

template <class T> bool Multiset<T>::deleteElt(T item){
	bool found = this->find_item(item);
	if (found){
		this->current.erase(this->current.begin()+this->location);
		count.erase(count.begin()+this->location);
	}
	return found;
};

template <class T> int Multiset<T>::reduceElt(T item, double num){
	if (this->find_item(item)){
		if (count[this->location] <= num){
			deleteElt(item);
			return 1;				//item deleted
		} else {
			count[this->location] -= num;
			return 0;				//item reduced
		}
	} else{
		return 2;					//item not found
	}
};

//extra helper function that will return the count associated with a given item
template <class T> double Multiset<T>::item_count(T item){
	if (this->find_item(item)) {
		return count[this->location];
	}
	else {
		return 0;
	}
};

template <class T> double Multiset<T>::get_count(int i) const{
	return count[i];
}

//helper
template <class T> int Multiset<T>::min(int a, int b){
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

//helper
template <class T> int Multiset<T>::abs(int a, int b){
	int c = a - b;
	if (c < 0){
		c *= -1;
	}
	return c;
}

//helper
template <class T> void Multiset<T>::resize(int a) {
	this->current.resize(a);
	count.resize(a);
}

template <class T> Multiset<T> Multiset<T>::operator+ (const Multiset<T> & rhs) {
	Multiset<T> temp(this->size() + rhs.size());
	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i), this->get_count(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.addElt(rhs.get_name(i), rhs.get_name(i));
	}
	return temp;
}

template <class T> Multiset<T> Multiset<T>::operator- (const Multiset<T> & rhs) {
	Multiset<T> temp(this->size() + rhs.size());
	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i), this->get_count(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.reduceElt(rhs.get_name(i), rhs.get_name(i));
	}
	return temp;
}

//intersect
template <class T> Multiset<T> Multiset<T>::operator* (const Multiset<T> & rhs) {
	Multiset<T> temp;
	for (int i = 0; i < this->get_size(); ++i)
	{
		for (int j = 0; j < rhs.get_size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i), min(this->get_count(i), rhs.get_count(i)));
			}
		}
	}
	return temp;
}

//difference
template <class T> Multiset<T> Multiset<T>::operator^ (Multiset<T> & rhs) {
	Multiset<T> temp;
	for (int i = 0; i < this->get_size(); ++i)
	{
		if(!rhs.find_item(this->get_name(i))){
			temp.addElt(this->get_name(i), this->get_count(i));
		}
		//catches all similar items but gets the difference in count
		else if (rhs.find_item(this->get_name(i))) {
			temp.addElt(this->get_name(i), abs(this->get_count(i), rhs.get_count(i)));
		}
	}
	for (int i = 0; i < rhs.get_size(); ++i)
	{
		if(!this->find_item(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i), rhs.get_count(i));
		}
	}
	return temp;
}

//deep copy
template <class T> Multiset<T> & Multiset<T>::operator= (const Multiset<T> & rhs) {
	if(this == &rhs) return *this;
	this->clear();
	this->resize(rhs.get_size());
	for (int i = 0; i < rhs.get_size(); ++i)
	{
		this->addElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to union
template <class T> Multiset<T> & Multiset<T>::operator+= (const Multiset<T> & rhs) {
	for (int i = 0; i< rhs.get_size(); ++i)
	{
		this->addElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to subtract
template <class T> Multiset<T> & Multiset<T>::operator-= (const Multiset<T> & rhs) {
	for (int i = 0; i < rhs.get_size(); ++i)
	{
		this->reduceElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to intersect
template <class T> Multiset<T> & Multiset<T>::operator*= (const Multiset<T> & rhs) {
	Multiset<T> temp;
	for (int i = 0; i < this->get_size(); ++i)
	{
		for (int j = 0; j < rhs.get_size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i), min(this->get_count(i), rhs.get_count(i)));
			}
		}
	}
	this->clear();
	this->resize(temp.get_size());
	this = temp;
	return *this;
}

//set to difference
template <class T> Multiset<T> & Multiset<T>::operator^= (Multiset<T> & rhs) {
	Multiset<T> temp;
	for (int i = 0; i < this->get_size(); ++i)
	{
		if(!rhs.find_item(this->get_name(i))){
			temp.addElt(this->get_name(i), this->get_count(i));
		}
		//catches all similar items but gets the difference in count
		else if (rhs.find_item(this->get_name(i))) {
			temp.addElt(this->get_name(i), abs(this->get_count(i), rhs.get_count(i)));
		}
	}
	for (int i = 0; i < rhs.get_size(); ++i)
	{
		if(!this->find_item(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i), this->get_count(i));
		}
	}
	this->clear();
	this = temp;
	return *this;
}

//equality
template <class T> bool Multiset<T>::operator== (const Multiset<T> & rhs) const {
	if (this->get_size() != rhs.get_size()) return false;
	for (int i = 0; i < this->get_size(); ++i)
	{
		if (this->get_name(i) != rhs.get_name(i)) return false;
		if (this->get_count(i) != rhs.get_count(i)) return false;
	}
	return true;
}

//proper subset
template <class T> bool Multiset<T>::operator< (const Multiset<T> & rhs) const {
	if (this->get_size() >= rhs.get_size()) return false;
	for (int i = 0; i < this->get_size(); ++i)
	{
		if (this->get_name(i) != rhs.get_name(i)) return false;
		if (this->get_count(i) > rhs.get_count(i)) return false;		
	}
	return true;
}

//subset
template <class T> bool Multiset<T>::operator<= (const Multiset<T> & rhs) const {
	if (this->get_size() > rhs.get_size()) return false;
	for (int i = 0; i < this->get_size(); ++i)
	{
		if (this->get_name(i) != rhs.get_name(i)) return false;
		if (this->get_count(i) > rhs.get_count(i)) return false;

	}
	return true;
}

//output
template <class T> ostream & operator<< (ostream & os, const Multiset<T> & rhs) {
	for (int i = 0; i < rhs.get_size(); ++i)
	{
		os << rhs.get_name(i) << " " << rhs.get_count(i);
	}
	return os;
}
//not sure how he wants this implemented
template <class T> istream & operator>> (istream & os, const Multiset<T> & rhs) {
	
}

/////////////////////////////////////////////////////

#endif