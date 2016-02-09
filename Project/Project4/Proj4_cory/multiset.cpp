#include "Set.h"
#include "multiset.h"
#include <iostream>			//library for input/output functions
#include <sstream>

////////////MULTISET//////////////////////////////////////
template <class T> Multiset<T>::Multiset() {
};

template <class T> void Multiset<T>::reset() {
	this->current.clear();
	count.clear();
};

template <class T> void Multiset<T>::print() {
	for (int i = 0; i < this->current.size(); i++){
		cout << count[i] << " " << this->current[i] << endl;
	}
};

template <class T> void Multiset<T>::insert_item(T item, double num){
	if (this->find_item(item)){
		count[this->location] += num;
	} else{
		this->current.push_back(item);
		count.push_back(num);
	}
};

template <class T> bool Multiset<T>::delete_item(T item){
	bool found = this->find_item(item);
	if (found){
		this->current.erase(this->current.begin()+this->location);
		count.erase(count.begin()+this->location);
	}
	return found;
};

template <class T> int Multiset<T>::reduce_item(T item, double num){
	if (this->find_item(item)){
		if (count[this->location] <= num){
			delete_item(item);
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

template <class T> double Multiset<T>::get_count(int i){
	return count[i];
}


//operator overloading
const Multiset template <class T> Multiset<T>::operator+(const Multiset & yourMultiSet) const;  //union
const Multiset template <class T> Multiset<T>::operator-(const Multiset & yourMultiSet) const;  //subtraction
const Multiset template <class T> Multiset<T>::operator*(const Multiset & yourMultiSet) const;  //intersect
const Multiset template <class T> Multiset<T>::operator^(const Multiset & yourMultiSet) const;  //difference

Multiset & template <class T> Multiset<T>::operator=(const Multiset & yourMultiSet);  //deep copy
Multiset & template <class T> Multiset<T>::operator==(const Multiset & yourMultiSet);  //equality
Multiset & template <class T> Multiset<T>::operator<(const Multiset & yourMultiSet);  //proper subset
Multiset & template <class T> Multiset<T>::operator<=(const Multiset & yourMultiSet);  //subset

ostream & template <class T> Multiset<T>::operator<<(ostream & os, const Multiset myMultiset){
	for (int i = 0; i < this->current.size(); i++){
		os << count[i] << " " << this->current[i] << endl;
	}

}
istream & template <class T> Multiset<T>::operator>>(istream & is, const Multiset myMultiSet){
	for (int i = 0; i < myMultiSet.size(); i++){
		cout[i] = myMultiSet.count[i];
		this->current[i] = myMultiSet,current[i];

	}

}



/////////////////////////////////////////////////////

/////////////RECIPE/////////////////////////////////

Recipe::Recipe(string t) {
	title = t;
}

void Recipe::add_ingredient(string a, double b) {
	ingredients.insert_item(a, b);
}

void Recipe::add_instruction(string a) {
	instructions = a;
}

void Recipe::add_equipment(string a, int b) {
	equipment.insert_item(a, b);
}

string Recipe::get_title() {
	return title;
}

string Recipe::get_instruction() {
	return instructions;
}

Multiset<string> Recipe::get_ingredients() {
	return ingredients;
}

Multiset<string> Recipe::get_equipment() {
	return equipment;
}
