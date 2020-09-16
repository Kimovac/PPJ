#include "angle.hpp"

using namespace std;

Angle::Angle(int angle) {
	_angles.push_back(angle);
}

Angle::Angle(int h, int m, int s) {
	_angles.push_back(h*3600 + m*60 + s);
}

Angle::Angle(Angle &p) {
	_angles = p._angles;
}

Angle* Angle::index(const int &i) {
	return new Angle(_angles[i]);
}

void Angle::insert(const Angle &p) {
	_angles.push_back(p._angles[0]);
}

int Angle::size() {
	return _angles.size();
}

bool Angle::operator ==(const Angle &p) {
	if(_angles[0] == p._angles[0])
		return true;
	else
		return false;
}

bool Angle::operator !=(const Angle &p) {
	if(_angles[0] != p._angles[0])
		return true;
	else
		return false;
}

bool Angle::operator >=(const Angle &p) {
	if(_angles[0] >= p._angles[0])
		return true;
	else
		return false;
}

bool Angle::operator <=(const Angle &p){
	if(_angles[0] <= p._angles[0])
		return true;
	else
		return false;
}

bool Angle::operator >(const Angle &p) {
	if(_angles[0] > p._angles[0])
		return true;
	else
		return false;
}
bool Angle::operator <(const Angle &p) {
	if(_angles[0] < p._angles[0])
		return true;
	else
		return false;
}

Angle* Angle::operator +(const Angle &p) {
	return new Angle(_angles[0] + p._angles[0]);
}

Angle* Angle::operator -(const Angle &p) {
	return new Angle(_angles[0] - p._angles[0]);
}

Angle* Angle::scalar_mul(const int p) {
	return new Angle(_angles[0] * p);
}
Angle* Angle::scalar_div(const int p) {
	return new Angle(_angles[0] / p);
}

Angle* Angle::max() {
	auto it = _angles.begin();
	int max = *it;
	for(++it; it != _angles.end(); it++) {
		if(*it > max)
			max = *it;
	}

	return new Angle(max);
}

Angle* Angle::min() {
	auto it = _angles.begin();
	int min = *it;
	for(++it; it != _angles.end(); it++) {
		if(*it < min)
			min = *it;
	}
	
	return new Angle(min);
}

Angle* Angle::avg() {	
	int sum = 0;
	for(auto it = _angles.begin(); it != _angles.end(); it++)
		sum += *it;

	return new Angle(sum / _angles.size());
}

void Angle::print(ostream &s) const {
	int n = _angles.size();
	if(n > 1) {
		cout << "[";
		int i = 0;
		for(auto x : _angles) {
			if(i != n-1)
				s << to_deg(x) << ", " ;
			else
				s << to_deg(x);
			i++;
		}
		cout << "]";
	}
	else
		s << to_deg(_angles[0]);

	s << endl;
}

string to_deg(const int &p) {
	int h = p/3600;
	int m = (p - h*3600)/60;
	int s = p - 3600*h - 60*m;

	string angle = to_string(h) + "." + 
	((m < 10) ? ("0" + to_string(m)) : to_string(m)) + "." + 
	((s < 10) ? ("0" + to_string(s)) : to_string(s));

	return angle;
}

ostream& operator <<(ostream &s, const Angle &p) {
	p.print(s);
	return s;
}
