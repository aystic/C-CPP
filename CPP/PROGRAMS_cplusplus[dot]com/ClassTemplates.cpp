/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 13:14:24
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 13:20:15
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

template<class T>
class rectangle {
public:
	T length;
	T breadth;
	rectangle(T a = 0, T b = 0): length(a), breadth(b) {};
	T area() {
		return length * breadth;
	}
	T perimeter() {
		return 2 * length * breadth;
	}
	void get();
};

template<class T>
void rectangle<T>::get() {
	cout << "length is " << length;
	cout << endll << "breadth is " << breadth << endll;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------


	rectangle<double> r1{2.25, 5.75};
	cout << r1.area() << endll;
	cout << r1.perimeter() << endll;
	r1.get();
	rectangle<int> r2{11, 99};
	cout << r2.area() << endll;
	cout << r2.perimeter() << endll;
	r2.get();

	return 0;
}