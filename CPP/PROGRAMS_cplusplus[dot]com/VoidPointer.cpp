/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 08:53:45
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 08:55:31
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

	int a = 1000;
	double pi = 3.14159;
	void *ptr;
	ptr = &a;
	cout << *((int *)ptr) << endll;
	ptr = &pi;
	cout << *((double *)ptr) << endll;

	return 0;
}