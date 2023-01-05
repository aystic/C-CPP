/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 08:57:42
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 09:04:19
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

int addition(int a, int b) {
	return a + b;
}

int subtraction(int a, int b) {
	return a - b;
}

int operation(int a, int b, int (*functocall)(int, int )) {
	int result;
	result = functocall(a, b);
	return result;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int (*minus)(int, int) = subtraction;
	// int(*plus)(int , int) = addition;
	int(*plus)(int , int);
	plus = &addition;
	cout << operation(99, 11, plus) << endll;
	cout << operation(99, 11, minus) << endll;
	cout << minus(999, 111) << endll;
	cout << plus(999, 111) << endll;

	return 0;
}