/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 22:47:24
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 23:04:12
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class polygon {
public:
	int height;
	int base;
	polygon(int a = 1, int b = 1): height(a), base(b) {};

};

class rectangle: public polygon {
public:
	// rectangle(int a = 1, int b = 1) {
	// 	height = a;
	// 	base = b;
	// };
	rectangle(int a, int b): polygon(a, b) {};
	int area() {
		return height * base;
	}
};

class triangle: public polygon {
public:
	// triangle(int a = 1, int b = 1) {
	// 	height = a,
	// 	base = b;
	// };
	triangle(int a, int b): polygon(a, b) {};
	double area() {
		return 0.5 * base * height;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------
	rectangle r{5, 10}; //Default base constructor is called
	triangle t{5, 10}; //Default base constructor is called
	cout << r.area() << endll;
	cout << t.area() << endll;


	return 0;
}