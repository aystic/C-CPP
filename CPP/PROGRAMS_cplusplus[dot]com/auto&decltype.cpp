/*
* @Author: Mohit Pathak
* @Date:   2021-05-22 12:02:44
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-22 12:04:34
*/

//#include<bits/stdc++.h>
#include<iostream>

#define endll '\n'
using namespace std;
//==============================================




//==============================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//================================================

	auto a = 3.14159;
	decltype(a) b;

	cout << typeid(a).name() << endll;
	cout << typeid(b).name() << endll;

	return 0;
}