/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 04:08:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 04:09:56
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

int myfunc(int a, int b) {
	return a + b;
}
int myfunc(double a, double b) {
	return a - b;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	cout << myfunc(5, 10) << endll;
	cout << myfunc(3.22, 5.12) << endll;


	return 0;
}