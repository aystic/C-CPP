/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 10:55:34
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 13:13:11
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class dummy {
public:
	static int n;
	int a;
	dummy() {
		n++;
	}
	int static get();
};
int dummy::n = 0;
int dummy::get() {
	// return a is Invalid a static function cannnot access non-static members.
	return n;
}


class dummy1 {
public:
	int a, b;
	const int c = 3;
	static int d;
	dummy1() {
		a = 1;
		b = 2;
	}
	int get() const {
		d--;
		// a++; not valid as const functions cannot modify non static members
		// get1(); not valid as const functions cannnot call other non const functions
		return a * b * c * d;
	}
	int get1() {
		d--;
		return a * b * c;
	}
};
int dummy1::d = 5;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	// cout << dummy::n << endll;
	// dummy * a = new dummy[100];
	// cout << dummy::n << endll;
	// cout << a->n << endll;
	// cout << a->get() << endll;

	const dummy1 d;
	cout << d.a << endll;
	cout << d.b << endll;
	cout << d.c << endll;
	cout << d.get() << endll;
	// cout << d.get1() << endll not valid as const object cannot call non-const functions
	dummy1 e;
	cout << e.get() << endll;
	cout << e.get1() << endll;
	return 0;
}