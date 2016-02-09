#ifndef MySet_0331
#define MySet_0331

#include <vector>
#include <string>
#include <iostream>
using namespace std;

////////////////////class/////////////////////////////

template <class T> class MySet{
	protected:
		vector<T> current;
		unsigned int location;
		
	public:
		MySet();
		void clear();
		void print() const;
		bool find(T);
		void addElt(T);
		bool deleteElt(T);
		T get_name(int) const;
		int size() const;
		int get_location() const;
		int compare(MySet<T> &);

		MySet<T> operator+ (const MySet<T> & rhs);		//union
		MySet<T> operator- (const MySet<T> & rhs);		//subtract
		MySet<T> operator* (const MySet<T> & rhs);		//intersect
		MySet<T> operator^ (MySet<T> & rhs);			//difference
		MySet<T> & operator= (const MySet<T> & rhs);	//deep copy
		MySet<T> & operator+= (const MySet<T> & rhs);	//Set to union
		MySet<T> & operator-= (const MySet<T> & rhs);	//Set to subtract
		MySet<T> & operator*= (const MySet<T> & rhs);	//Set to intersect
		MySet<T> & operator^= (MySet<T> & rhs);			//Set to difference
		int operator== (MySet<T> & rhs) const;	//equality
		int operator< (MySet<T> & rhs) const; 	//proper subset
		int operator<= (MySet<T> & rhs) const;	//subset
		template<class Y> friend ostream & operator<< (ostream & os, const MySet<Y> & rhs);	//stream out
		template<class Y> friend istream & operator>> (istream & os, const MySet<Y> & rhs); //stream in
};

/////////////////////////////////////////////////////////////////////////

////////////////IMPLEMENTATION//////////////////////////////////////////
template <class T> MySet<T>::MySet() {
}

template <class T> void MySet<T>::clear() {current.clear();}

template <class T> void MySet<T>::print() const {
	for (int i = 0; i < current.size(); ++i)
	{
		cout << current[i];
	}
}

template <class T> bool MySet<T>::find(T item) {
	for (int i = 0; i < current.size(); i++){
		if (current[i] == item) {
			location = i;
			return true;;
		}
	}
	return false;
}

template <class T> void MySet<T>::addElt(T item) {
	if (!find(item)){
		current.push_back(item);
	}
}

template <class T> bool MySet<T>::deleteElt(T item) {
	bool found = find(item);
	if (found){
		current.erase(current.begin()+location);
	}
	return found;
}

template <class T> T MySet<T>::get_name(int i) const {return current[i];}

template <class T> int MySet<T>::size() const {return current.size();}

template <class T> int MySet<T>::get_location() const {return location;}

template <class T> int MySet<T>::compare(MySet<T> & other) {
	if (this == &other) return 0;
	if (this->size() <= other.size()) {
		for (int i = 0; i < this->size(); ++i)
		{
			if (!other.find(this->get_name(i))) return 2;
		}
		return -1;
	}
	if (this->size() >= other.size()) {
		for (int i = 0; i < other.size(); ++i)
		{
			if (!this->find(other.get_name(i))) return 2;
		}
		return 1;
	}
}

//union
template <class T> MySet<T> MySet<T>::operator+ (const MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.addElt(rhs.get_name(i));
	}
	return temp;
}

//subtract
template <class T> MySet<T> MySet<T>::operator- (const MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.deleteElt(rhs.get_name(i));
	}
	return temp;
}

//intersect
template <class T> MySet<T> MySet<T>::operator* (const MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		for (int j = 0; j < rhs.size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i));
			}
		}
	}
	return temp;
}

//difference
template <class T> MySet<T> MySet<T>::operator^ (MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		if(!rhs.find(this->get_name(i))){
			temp.addElt(this->get_name(i));
		}
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		if(!this->find(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i));
		}
	}
	return temp;
}

//deep copy
template <class T> MySet<T> & MySet<T>::operator= (const MySet<T> & rhs) {
	if(this == &rhs) return *this;
	this->clear();
	for (int i = 0; i < rhs.size(); ++i)
	{
		this->addElt(rhs.get_name(i));
	}
	return *this;
}

//Set to union
template <class T> MySet<T> & MySet<T>::operator+= (const MySet<T> & rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		this->addElt(rhs.get_name(i));
	}
	return *this;
}

//Set to subtract
template <class T> MySet<T> & MySet<T>::operator-= (const MySet<T> & rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		this->deleteElt(rhs.get_name(i));
	}
	return *this;
}

//Set to intersect
template <class T> MySet<T> & MySet<T>::operator*= (const MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		for (int j = 0; j < rhs.size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i));
			}
		}
	}
	this->clear();
	this = temp;
	return *this;
}

//Set to difference
template <class T> MySet<T> & MySet<T>::operator^= (MySet<T> & rhs) {
	MySet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		if(!rhs.find(this->get_name(i))){
			temp.addElt(this->get_name(i));
		}
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		if(!this->find(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i));
		}
	}
	this->clear();
	this = temp;
	return *this;
}

//equality
template <class T> int MySet<T>::operator== (MySet<T> & rhs) const {
	if (this->size() != rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
	}
	return 1;
}

//proper subMySet
template <class T> int MySet<T>::operator< (MySet<T> & rhs) const {
	if (this->size() >= rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
	}
	return 1;
}

//subMySet
template <class T> int MySet<T>::operator<= (MySet<T> & rhs) const {
	if (this->size() > rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
	}
	return 1;
}

//output
template <class T> ostream & operator<< (ostream & os, const MySet<T> & rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		os << rhs.get_name(i);
	}
	return os;
}
//input
template <class T> istream & operator>> (istream & is, const MySet<T> & rhs) {
	MySet<T> temp;
	while(is){
		is >> temp;
		rhs.addElt(temp);
	}
	return is;
}

#endif