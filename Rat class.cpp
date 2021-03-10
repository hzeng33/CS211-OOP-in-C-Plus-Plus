// Rat class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>

using namespace std;

class Rat {
private:
	int n; //numerator
	int d; //denaminator
public:
	// constructors

	// default constructor
	Rat() {
		n = 0;
		d = 1;
	}

	// 2 parameters constructor
	Rat(int i, int j) {
		n = i;
		d = j;
	}
	// conversion constructor
	Rat(int i) {
		n = i;
		d = 1;
	}

	//accessor functions (usually called get() and set(...) )
	int getN() { return n; }
	int getD() { return d; }
	void setN(int i) { n = i; }
	void setD(int i) { d = i; }

	//arithmetic operators

	Rat operator+(Rat r) {
		Rat t;
		t.n = n * r.d + d * r.n;
		t.d = d * r.d;
		return t;
	}

	Rat operator-(Rat r) {
		Rat s;
		s.n = n * r.d - d * r.n;
		s.d = d * r.d;
		return s;
	}

	Rat operator*(Rat r) {
		Rat m;
		m.n = n * r.n;
		m.d = d * r.d;
	
		return m;
	}

	Rat operator/(Rat r) {
		Rat t;
		t.n = n * r.d;
		t.d = d * r.n;
		return t;
	}
	// 2 overloaded i/o operators
	friend ostream& operator<<(ostream& os, Rat r);
	friend istream& operator>>(istream& is, Rat& r);
}; //end Rat
   // operator<<() is NOT a member function but since it was declared a friend of Rat
   // it has access to its private parts.

int gcd(int a, int b) {//this function returns the gcd through recursion
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}

ostream& operator<<(ostream& os, Rat r) {
	if (r.n > r.d) {//if it is an improper fraction, it must be reduced
		if (r.n%r.d == 0) {
			os << r.n / r.d << endl;
		}
		else {
			int x = gcd(r.n%r.d, r.d);//just in case the reduced fraction needs to be reduced further
			os << r.n / r.d << " " << (r.n%r.d) / x << " / " << (r.d) / x << endl;
		}
	}
	else if (r.n == 0) {
		os << r.n << endl;//if the numerator is 0, then return 0
	} else {
		int x = gcd(r.n%r.d, r.d);//reduce the proper fraction
		os << r.n / x << " / " << r.d / x << endl;
	}

	os << r.n/r.d <<" "<< r.n << " / " << r.d << endl;
	return os;
}

Rat reduce(int &i, int &j) {//this function reduces r.d and r.n accordingly so it can be used
	for (int a = i; a > 0; a--) {
		if (i%a == 0 && j%a == 0) {
			i = i / a;
			j = j / a;
			break;
		}
	}
	return Rat(i, j);
}// end of reduce

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r) {
	is >> r.n >> r.d;
	reduce(r.n, r.d);
	return is;
}

int main() {
	Rat x(1, 2), y(2, 3);
	cout << "x:" << x<< endl;
	cout << "y:" << y << endl;
	cout << "x+y: " << x+y<< endl;
	cout << "x-y: " << x-y << endl;
	cout << "x*y: " << x*y << endl;
	cout << "x/y: " << x/y << endl;
	cout << endl;

	return 0;
}


