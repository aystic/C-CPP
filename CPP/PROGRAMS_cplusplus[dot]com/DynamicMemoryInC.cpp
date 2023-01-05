/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 12:42:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 12:49:14
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cstdlib>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int *a = (int*)malloc(sizeof(int));
	*a = 999;
	cout << *a << endll;
	int *arr = (int*)malloc(9999999999 * sizeof(int));
	if (!arr) {
		cout << "Allocation failed" << endll;
	}

	void *x = calloc(100, sizeof(int));
	int*z = (int*)x;
	for (int i = 0; i < 99; ++i)
	{
		cout << z[i] << " ";
	}
	cout << endll;
	int *y = (int *)calloc(9999999999999, sizeof(int));
	if (!y) {
		cout << "Allocation failed" << endll;
	}


	return 0;
}