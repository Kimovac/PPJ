#ifndef angle_hpp
#define angle_hpp

#include <iostream>
#include <vector>
#include <ostream>

using namespace std;

class Angle {
	private:
		vector<int> _angles;

	public:
		Angle() {};
		Angle(int angle);
		Angle(int h, int m, int s);
		Angle(Angle &p);

		Angle* index(const int &i);

		void insert(const Angle &p);

		int size();

		bool operator ==(const Angle &p);
		bool operator !=(const Angle &p);
		bool operator >=(const Angle &p);
		bool operator <=(const Angle &p);
		bool operator >(const Angle &p);
		bool operator <(const Angle &p);

		Angle* operator +(const Angle &p);
		Angle* operator -(const Angle &p);

		Angle* scalar_mul(const int p);
		Angle* scalar_div(const int p);

		Angle* max();
		Angle* min();
		Angle* avg();

		void rad_print();

		void print(ostream &s) const;
};

string to_deg(const int &p);

ostream& operator <<(ostream &s, const Angle &p);

#endif
