/*
* @Author: Mohit Pathak
* @Date:   2021-05-30 11:35:54
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-04 08:12:25
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class polygon {
protected:
	int height, width;
public:
	polygon(int a = 1, int b = 1): height(a), width(b) {};
	// virtual double area() = 0; //this is a pure virtual function : makes the class as abstract base class
	virtual double area() {return 0;}//this is a virual function
};

class rectangle: public polygon {
public:
	rectangle(int a = 1, int b = 1): polygon(a, b) {};
	double area() {
		return height * width;
	}
};

class triangle: public polygon {
public:
	triangle(int a = 1, int b = 1): polygon(a, b) {};
	double area() {
		return 0.5 * height * width;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	rectangle r{5, 10};
	triangle t{5, 10};
	polygon * ptr1, *ptr2, *ptr3;
	ptr1 = &r;
	ptr2 = &t;
	cout << r.area() << " " << ptr1->area() << endll;
	cout << t.area() << " " << ptr2->area() << endll;
	cout << ptr3->area() << endll;

	return 0;
}