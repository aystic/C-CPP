/*
* @Author: Mohit Pathak
* @Date:   2021-06-13 02:32:13
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-13 02:40:39
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

	string s = "45";
	int x;
	stringstream input(s);
	input >> x;
	cout << x + 55 << endl;
	return 0;
}