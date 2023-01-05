/*
* @Author: Mohit Pathak
* @Date:   2021-06-19 21:20:12
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-19 21:21:04
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char ch = 'A';
	cout << ch << endl; //PRINTS A
	cout << &ch << endl; //PRINTS A DUE TO OPERATOR OVELOADING
	cout << (void*)&ch << endl; //PRINTS ADDRESS

	return 0;
}