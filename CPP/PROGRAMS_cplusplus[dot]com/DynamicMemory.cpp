/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 12:23:40
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 12:41:03
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<new>
using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int* a = new (nothrow) int;
	int *arr1 = new (nothrow) int[100];
	*a = 999;
	for (int i = 0; i < 99; ++i)
	{
		arr1[i] = i;
	}
	cout << *a << endll;
	for (int i = 0; i < 99; ++i)
	{
		cout << arr1[i] << " ";
	}
	cout << endll;

	try {
		int *arr = new int[999999999999999999];
	}
	catch (bad_alloc & b) {
		cerr << "Bad_allocation error thrown " << b.what() << endll;
	}

	return 0;
}