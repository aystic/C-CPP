/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 04:10:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 15:13:41
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

template<class T>
T add(T a, T b) {
	return a + b;
}

template<typename S>
S subtract(S a, S b) {
	return b - a;
}

template < class T, class U>
double add2(T a, U b) {
	return a + b;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	cout << add<int>(11, 99) << endll;//or add (11,99) both works
	cout << add<double>(11.11, 99.9945) << endll;
	cout << subtract(1, 5) << endll;
	cout << subtract(2.5, 6.453) << endll;
	cout << add2(2, 22.22) << endll;
	return 0;
}