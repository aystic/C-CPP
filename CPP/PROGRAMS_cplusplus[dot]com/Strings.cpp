/*
* @Author: Mohit Pathak
* @Date:   2021-05-22 12:08:12
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-22 12:10:18
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#define endll '\n'
using namespace std;
//==============================================




//==============================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//================================================

	string str1, str2;
	str1 = "Mohit";
	str2 = "Pathak";

	cout << str1 + str2 << endl;

	if (str1 > str2) {
		cout << "Mohit is bigger than pathak" << endll;
	} else {
		cout << "Otherwise" << endll;
	}

	return 0;
}