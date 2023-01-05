/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 22:35:47
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 22:45:25
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------
#define pi 3.14159
class cylinder;
class base {
	int radius;
public:
	base(int a = 1): radius(a) {};
	friend class cylinder;
};

class cylinder {
	base b;
	int height;
public:
	cylinder(int r, int h): b(r), height(h) {};
	void display() {
		cout << "Radius is " << b.radius << endll;
		cout << "height is " << height << endll;
		cout << "Area is " << pi*b.radius*b.radius << endll;
		cout << "volume is " << volume() << endll;
	}
	double volume() {
		double area = pi * b.radius * b.radius;
		return area * height;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	cylinder c{5, 10};
	cout << c.volume() << endll;
	c.display();

	return 0;
}