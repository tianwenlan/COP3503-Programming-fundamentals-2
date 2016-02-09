#ifndef MySet_0331
#define MySet_0331

#include <vector>
#include <string>
#include <iostream>
using namespace std;

////////////////////class/////////////////////////////

template <class> class MySet;
template <class T> ostream& operator<<(ostream&, const MySet<T>);
template <class T> istream& operator>>(istream&, MySet<T> &);

template <class T> class MySet{
	protected:
		vector<T> current;
		unsigned int location;
		
	public:
		MySet();
		virtual void clear();
		bool find(T) ;
		void addElt(T);
		bool deleteElt(T);
		T get_name(int) const;
		int size() const;
		int get_location() const;
		int compare(MySet<T> &);
		bool readSet(MySet<T> &m);

		MySet<T> operator+ (const MySet<T> &) const;		//union
		MySet<T> operator- (const MySet<T> &) const;		//subtract
		MySet<T> operator* (const MySet<T> &) const;		//intersect
		MySet<T> operator^ (MySet<T> &);			//difference
		MySet<T> & operator= (const MySet<T> &);	//deep copy
		MySet<T> & operator+= (const MySet<T> &);	//Set to union
		MySet<T> & operator-= (const MySet<T> &);	//Set to subtract
		MySet<T> & operator*= (const MySet<T> &);	//Set to intersect
		MySet<T> & operator^= (MySet<T> & rhs);			//Set to difference
		int operator== (MySet<T> & rhs) const;	//equality
		int operator< (MySet<T> & rhs) const; 	//proper subset
		int operator<= (MySet<T> & rhs) const;	//subset
		friend ostream & operator<< <T>(ostream &, const MySet<T>);	//stream out
		friend istream & operator>> <T>(istream &, MySet<T> &); //stream in
};

template <class> class MyMultiSet;
template <class T> ostream& operator<<(ostream&, const MyMultiSet<T>);
template <class T> istream& operator>>(istream&, MyMultiSet<T> &);

template<class T> class MyMultiSet : public MySet<T>{
	private:
		vector<int> count;
		int min(int, int) const;//helper
		int abs(int, int) const; //helper
						
	public:
		MyMultiSet();
		void clear() ;
		void addElt(T, int);
		bool deleteElt(T);
		int reduceElt(T, int);
		int item_count(T);
		int get_count(int) const;
		int compare(MyMultiSet<T> &);
		bool input(MyMultiSet<T> &);

		MyMultiSet<T> operator+ (const MyMultiSet<T> & rhs) const;	//union
		MyMultiSet<T> operator- (const MyMultiSet<T> & rhs) const;	//subtract
		MyMultiSet<T> operator* (const MyMultiSet<T> & rhs) const;		//intersect
		MyMultiSet<T> operator^ (MyMultiSet<T> & rhs);		//difference
		MyMultiSet<T> & operator= (const MyMultiSet<T> & rhs);	//deep copy
		MyMultiSet<T> & operator+= (const MyMultiSet<T> & rhs);	//set to union
		MyMultiSet<T> & operator-= (const MyMultiSet<T> & rhs);	//set to subtract
		MyMultiSet<T> & operator*= (const MyMultiSet<T> & rhs);	//set to intersect
		MyMultiSet<T> & operator^= (MyMultiSet<T> & rhs);	//set to difference
		int operator== (MyMultiSet<T> & rhs) const;	//equality
		int operator< (MyMultiSet<T> & rhs) const; 	//proper subset
		int operator<= (MyMultiSet<T> & rhs) const;	//subset
		friend ostream & operator<< <T>(ostream &, const MyMultiSet<T>);	//stream out
		friend istream & operator>> <T>(istream &, MyMultiSet<T> &); //stream in
};


////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////IMPLEMENTATION//////////////////////////////////////////
template <class T> MySet<T>::MySet() {
}

template <class T> void MySet<T>::clear() {current.clear();}

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

	if(*this==other){
		return 0;
	}else if((*this < other)==1){
		return -1;
	}else if((other < *this)==1){
		return 1;
	}else {
		return 2;
	}
}

//union
template <class T> MySet<T> MySet<T>::operator+ (const MySet<T> & rhs) const {
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
template <class T> MySet<T> MySet<T>::operator- (const MySet<T> & rhs) const {
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
template <class T> MySet<T> MySet<T>::operator* (const MySet<T> & rhs) const {
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

	for(int i =0; i< temp.size(); ++i){
		this->addElt(temp.get_name(i));
	}

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
		
	for(int i =0; i< temp.size(); ++i){
		this->addElt(temp.get_name(i));
	}

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
template <class T> ostream & operator<< (ostream & os, const MySet<T> rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		os << rhs.get_name(i) << endl;
	}
	return os;
}
//input
template <class T> istream & operator>> (istream & is, MySet<T> & rhs) {
	T temp;
	while(is){
		is >> temp;
		if(is){
			rhs.addElt(temp);
		}else{
			cerr << "invalid input: " << temp << endl;
		}
	}
	return is;
}

///////////////////////////////////////////MultiSet///////////////////////////////////////////////


template <class T> MyMultiSet<T>::MyMultiSet() {
};

template <class T> void MyMultiSet<T>::clear() {
	this->current.clear();
	count.clear();
};

template <class T> void MyMultiSet<T>::addElt(T item, int num){
	if (this->find(item)){
		count[this->location] += num;
	} else{
		this->current.push_back(item);
		count.push_back(num);
	}
};

template <class T> bool MyMultiSet<T>::deleteElt(T item){
	bool found = this->find(item);
	if (found){
		this->current.erase(this->current.begin()+this->location);
		count.erase(count.begin()+this->location);
	}
	return found;
};

template <class T> int MyMultiSet<T>::reduceElt(T item, int num){
	if (this->find(item)){
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
template <class T> int MyMultiSet<T>::item_count(T item){
	if (this->find(item)) {
		return count[this->location];
	}
	else {
		return 0;
	}
};

template <class T> int MyMultiSet<T>::get_count(int i) const{
	return count[i];
}

template <class T> int MyMultiSet<T>::compare(MyMultiSet<T> & other) {

	if(*this==other){
		return 0;
	}else if((*this < other)==1){
		return -1;
	}else if((other < *this)==1){
		return 1;
	}else {
		return 2;
	}
}

//helper
template <class T> int MyMultiSet<T>::min(int a, int b) const{
	if (a < b) {
		return a;
	} else {
		return b;
	}
}

//helper
template <class T> int MyMultiSet<T>::abs(int a, int b) const{
	int c = a - b;
	if (c < 0){
		c *= -1;
	}
	return c;
}

template <class T> MyMultiSet<T> MyMultiSet<T>::operator+ (const MyMultiSet<T> & rhs) const {
	MyMultiSet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i), this->get_count(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.addElt(rhs.get_name(i), rhs.get_count(i));
	}
	return temp;
}

template <class T> MyMultiSet<T> MyMultiSet<T>::operator- (const MyMultiSet<T> & rhs)const {
	MyMultiSet<T> temp;

	for (int i = 0; i < this->size(); ++i)
	{
		temp.addElt(this->get_name(i), this->get_count(i));
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		temp.reduceElt(rhs.get_name(i), rhs.get_count(i));
	}
	return temp;
}

//intersect
template <class T> MyMultiSet<T> MyMultiSet<T>::operator* (const MyMultiSet<T> & rhs)const {
	MyMultiSet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		for (int j = 0; j < rhs.size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i), min(this->get_count(i), rhs.get_count(i)));
			}
		}
	}
	return temp;
}

//difference
template <class T> MyMultiSet<T> MyMultiSet<T>::operator^ (MyMultiSet<T> & rhs) {
	MyMultiSet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		if(!rhs.find(this->get_name(i))){
			temp.addElt(this->get_name(i), this->get_count(i));
		}
		//catches all similar items but gets the difference in count
		else if (rhs.find(this->get_name(i)) && (this->get_count(i) !=rhs.get_count(i))) {
			temp.addElt(this->get_name(i), abs(this->get_count(i), rhs.get_count(i)));
		}
	}
	for (int i = 0; i < rhs.size(); ++i)
	{
		if(!this->find(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i), rhs.get_count(i));
		}
	}
	return temp;
}

//deep copy
template <class T> MyMultiSet<T> & MyMultiSet<T>::operator= (const MyMultiSet<T> & rhs) {
	if(this == &rhs) return *this;
	this->clear();
	for (int i = 0; i < rhs.size(); ++i)
	{
		this->addElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to union
template <class T> MyMultiSet<T> & MyMultiSet<T>::operator+= (const MyMultiSet<T> & rhs) {
	for (int i = 0; i< rhs.size(); ++i)
	{
		this->addElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to subtract
template <class T> MyMultiSet<T> & MyMultiSet<T>::operator-= (const MyMultiSet<T> & rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		this->reduceElt(rhs.get_name(i), rhs.get_count(i));
	}
	return *this;
}

//set to intersect
template <class T> MyMultiSet<T> & MyMultiSet<T>::operator*= (const MyMultiSet<T> & rhs) {
	MyMultiSet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		for (int j = 0; j < rhs.size(); ++j)
		{
			if(this->get_name(i) == rhs.get_name(j)) {
				temp.addElt(this->get_name(i), min(this->get_count(i), rhs.get_count(i)));
			}
		}
	}
	this->clear();

	for(int i =0; i< temp.size(); ++i){
		this->addElt(temp.get_name(i), temp.get_count(i));
	}

	return *this;
}

template <class T> MyMultiSet<T> & MyMultiSet<T>::operator^= (MyMultiSet<T> & rhs) {
	MyMultiSet<T> temp;
	for (int i = 0; i < this->size(); ++i)
	{
		if(!rhs.find(this->get_name(i))){
			temp.addElt(this->get_name(i), this->get_count(i));
		}
		//catches all similar items but gets the difference in count
		else if (rhs.find(this->get_name(i)) && (this->get_count(i) != rhs.get_count(i))) {
			temp.addElt(this->get_name(i), abs(this->get_count(i), rhs.get_count(i)));
		}
	}

	for (int i = 0; i < rhs.size(); ++i)
	{
		if(!this->find(rhs.get_name(i))){
			temp.addElt(rhs.get_name(i), rhs.get_count(i));
		}
	}
	this->clear();

	for(int i =0; i< temp.size(); ++i){
		this->addElt(temp.get_name(i), temp.get_count(i));
	}

	return *this;
}

//equality
template <class T> int MyMultiSet<T>::operator== (MyMultiSet<T> & rhs) const {
	if (this->size() != rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
		else if (rhs.item_count(this->get_name(i)) != this->get_count(i)) return 0;
	}
	return 1;
}

//proper subset
template <class T> int MyMultiSet<T>::operator< (MyMultiSet<T> & rhs) const {
	if (this->size() >= rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
		if (rhs.item_count(this->get_name(i)) < this->get_count(i)) return 0;		
	}
	return 1;
}

//subset
template <class T> int MyMultiSet<T>::operator<= (MyMultiSet<T> & rhs) const {
	if (this->size() > rhs.size()) return 0;
	for (int i = 0; i < this->size(); ++i)
	{
		if (!rhs.find(this->get_name(i))) return 0;
		if (rhs.item_count(this->get_name(i)) <= this->get_count(i)) return 0;

	}
	return 1;
}

//output
template <class T> ostream & operator<< (ostream & os, const MyMultiSet<T> rhs) {
	for (int i = 0; i < rhs.size(); ++i)
	{
		os << rhs.get_name(i) << " " << rhs.get_count(i) << endl;
	}
	return os;
}
//input
template <class T> istream & operator>> (istream & is, MyMultiSet<T> & rhs) {
	string line;
	T tempName;
	int num;

	while(getline(is,line)){
		istringstream record(line);

		record >> tempName >> num;

		//error handle
		if (record.fail()) {
			if (line.empty()){
			//	if (!silent){
				cerr << "This line is empty" << endl;
			//	}
			}else if (!num){
			//	if(!silent){
			cerr << "<" << tempName << ">" <<"'s <count> is missing" << endl;
			//	}
			}else if (line!=""){
			//	if(!silent){
					cerr << "[" << line << "] is not in correct format on user input line" << endl;
			//	}
			}
			continue;
		}

		if(num <= 0){
		//	if(!silent){
				cerr << "[" << tempName << "] has invalid count number! <Count> should be larger than 0" << endl;
		//	}
		}else{
			rhs.addElt(tempName, num);
		}

		// now see if there is more stuff in the line
		if (!record.eof()){
			// try to read it
			record >> tempName;
			if (!record.fail())
			// if read a string, then bad line
	//			if (!silent){
				cerr << "line malformed: " << line << endl;
	//			}
			}

	// reset tempName to empty so we don't print junk
	//	tempName = "";

	}

	return is;
}



#endif
