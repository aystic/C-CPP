/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 04:04:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 04:05:51
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------


int add(int a = 0, int b = 0, int c = 0) {
	return a + b + c;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	cout << add() << endll;
	cout << add(1) << endll;
	cout << add(1, 2) << endll;
	cout << add(1, 2, 3) << endll;
	return 0;
}