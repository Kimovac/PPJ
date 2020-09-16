#ifndef nums_hpp
#define nums_hpp

#include <iostream>
#include <vector>
#include <string>
#include <ostream>

using namespace std;

class Num {
	private:
		vector<int> _values;

	public:
		Num(const Num &p);
		Num(const int p);

		bool is_list();
		int index(const int p) const;
		void add(const int p);

		bool operator ==(const Num &p);
		Num* operator +(const Num &p);
		Num* operator -(const Num &p);
		Num* operator *(const Num &p);
		Num* operator /(const Num &p);
		Num* operator &(const Num &p);
		Num* operator |(const Num &p);
		Num* operator <<(const Num &p);
		Num* operator >>(const Num &p);
		Num* operator ~();

		string base(const int base);

		void print(ostream &s) const;


};

ostream& operator <<(ostream &s, const Num &p);

#endif