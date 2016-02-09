#ifndef SET_0331
#define SET_0331

#include <vector>
#include <string>
using namespace std;

template <class T> class Set{
	protected:
		vector<T> current;
		unsigned int location;
	public:
		Set();
		void reset();
		void print();
		bool find_item(T);
		void insert_item(T);
		bool delete_item(T);
		T get_name(int);
		int get_size();
		int get_location();

		const Set operator+(const Set &) const;  //union
		const Set operator-(const Set &) const;  //subtraction
		const Set operator*(const Set &) const;  //intersect
		const Set operator^(const Set &) const;  //difference

		Set & operator=(const Set &);  //deep copy
		Set & operator==(const Set &);  //equality
		Set & operator<(const Set &);  //proper subset
		Set & operator<=(const Set &);  //subset

		friend ostream & operator<<(ostream &, const Set);  //stream out
		friend istream & operator>>(istream &, const Set);  //stream in

};

#endif
