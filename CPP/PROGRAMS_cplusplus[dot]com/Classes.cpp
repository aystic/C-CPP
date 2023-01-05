/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 09:31:42
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 09:40:52
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class rectangle {
private:
	int length;
	int breadth;
public:
	rectangle(int, int);
	double area();
	double perimeter();
};

rectangle::rectangle(int a = 0, int b = 0): length(a), breadth(b) {}

double rectangle::area() {
	return length * breadth;
}
double rectangle::perimeter() {
	return 2 * (length + breadth);
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	rectangle r1{10, 20};
	cout << r1.area() << endll;
	cout << r1.perimeter() << endll;

	return 0;
}