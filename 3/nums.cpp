#include "nums.hpp"

Num::Num(const Num &p) {
	_values = p._values;
}
Num::Num(const int p) {
	_values.push_back(p);
}

bool Num::is_list() {
	if(_values.size() == 1)
		return false;
	else
		return true;
}

int Num::index(const int p) const {
	return _values[p];
}

void Num::add(const int p) {
	_values.push_back(p);
}

bool Num::operator ==(const Num &p) {
	if(_values[0] == p._values[0])
		return true;
	else
		return false;
}

Num* Num::operator +(const Num &p) {
	return new Num(_values[0] + p._values[0]);
}

Num* Num::operator -(const Num &p) {
	return new Num(_values[0] - p._values[0]);
}

Num* Num::operator *(const Num &p) {
	return new Num(_values[0] * p._values[0]);
}

Num* Num::operator /(const Num &p) {
	return new Num(_values[0] / p._values[0]);
}

Num* Num::operator &(const Num &p) {
	return new Num(_values[0] & p._values[0]);
}
Num* Num::operator |(const Num &p) {
	return new Num(_values[0] | p._values[0]);
}

Num* Num::operator <<(const Num &p) {
	return new Num(_values[0] << p._values[0]);
}

Num* Num::operator >>(const Num &p) {
	return new Num(_values[0] >> p._values[0]);
}

Num* Num::operator ~() {
	return new Num(~(_values[0]));
}

string Num::base(const int base) {
	char s[20];
	if(base == 16)
		sprintf(s, "%#X",  _values[0]);
	if(base == 10)
		sprintf(s, "%d",  _values[0]);
	if(base == 8)
		sprintf(s, "%o",  _values[0]);

	return string(s);
}

void Num::print(ostream &s) const {
	int n = _values.size();
	cout << "[";
	for(int i=0; i<n; i++) {
		if(i != n-1)
			cout << _values[i] << ", ";
		else
			cout << _values[i];
	}
	cout << "]" << endl;
}

ostream& operator <<(ostream &s, const Num &p) {
	p.print(s);
	return s;
}