/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 09:49:28
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 09:57:07
*/

//#include<bits/stdc++.h>
#include<iostream>
#define pi 3.14159
using namespace std;
#define endll '\n'
//--------------------------------------

class circle {
	int radius;
public:
	circle() {
		radius = 0;
	}
	circle(int);
	double area();
};
circle::circle(int a): radius(a) {};
double circle::area() {
	return pi * radius * radius;
}

class cylinder {
	circle base;
	int height;
public:
	cylinder(int, int);
	double volume();
};

cylinder::cylinder(int a, int b): base(a), height(b) {};
double cylinder::volume() {
	return base.area() * height;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	cylinder c{5, 10};
	cout << "The volume is " << c.volume() << endll;

	return 0;
}