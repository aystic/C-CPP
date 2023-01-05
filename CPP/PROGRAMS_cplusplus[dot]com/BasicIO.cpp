/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 03:22:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 03:35:01
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	// string str;
	// char str1[100];
	// getline(cin, str);
	// cout << str << endl;
	// cin.get(str1, 100, '!');
	// cout << str1 << endl;

	string str2 = "12345";
	int myint;
	stringstream(str2) >> myint;
	cout << myint << endll;
	cout << typeid(myint).name() << endll;
	return 0;
}