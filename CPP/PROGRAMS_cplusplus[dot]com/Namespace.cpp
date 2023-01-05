/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 15:22:20
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 15:32:50
*/

//#include<bits/stdc++.h>
#include<iostream>

// using namespace std;
#define endll '\n'
//--------------------------------------

namespace my_std = std;
using namespace my_std;

namespace my_namespace {
int a = 10;
int b = 20;
int multiply() {
	return a * b;
}
}

namespace x {
int a = 1, b = 2;
}

namespace y {
int a = 2, b = 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	// cout << my_namespace::a << endll;
	// cout << my_namespace::b << endll;
	// cout << my_namespace::multiply() << endll;
	// using namespace y;
	using x::a;
	using y::b;
	cout << a << endll;
	cout << b << endll;
	return 0;
}