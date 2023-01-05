/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 08:11:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 08:21:46
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
	char arr[100] = "Hello world";
	string str = "Hello World";
	// arr = "Mohit";
	str = "Mohit Pathak";
	int length = sizeof("Mohit Pathak") / sizeof(char);
	for (int i = 0; i < length; ++i)
	{
		arr[i] = str[i];
	}
	cout << arr << endll;
	cout << str << endll;
	return 0;
}