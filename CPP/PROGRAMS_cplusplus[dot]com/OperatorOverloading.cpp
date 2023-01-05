/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 10:13:12
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 10:34:55
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class complex {
	int real;
	int img;
public:
	complex(int, int);
	complex operator +(const complex);
	complex operator -(const complex);
	friend ostream & operator <<(ostream &, const complex);//should be made a friend to access the private members
};

complex::complex(int a = 0, int b = 0): real(a), img(b) {};
complex complex::operator +(const complex arg) {
	complex temp;
	temp.real = real + arg.real;
	temp.img = img + arg.img;
	return temp;
}
complex complex::operator - (const complex arg) {
	complex temp;
	temp.real = real - arg.real;
	temp.img = img - arg.img;
	return temp;
}

ostream & operator <<(ostream & out, const complex temp) {//defined as a global function as cout and complex object both has to pass
	out << temp.real << " + " << "(" << temp.img << ")" << "i" << endll;
	return out;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	complex c1{9, 9}, c2{11, 11};
	cout << c1;
	cout << c2;
	complex result;
	result = c1 + c2;
	cout << result;
	result = c1 - c2;
	cout << result;
	return 0;
}