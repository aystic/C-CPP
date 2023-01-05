/*
* @Author: Mohit Pathak
* @Date:   2021-04-20 04:04:50
* @Last Modified by:  Mohit Pathak
* @Last Modified time: 2021-04-20 04:55:24
*/

//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//======================================
#define endll "\n"

//======================================

int size;

void display(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
}

void Generate(int *arr, int n) {
	if (n < 1) {
		display(arr, size);
		return;
	}
	else {
		arr[n - 1] = 0;
		Generate(arr, n - 1);
		arr[n - 1] = 1;
		Generate(arr, n - 1);
	}
}



//=======================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//=======================================

	int n;
	cin >> n;
	size = n;
	int arr[n];
	Generate(arr, n);
	return 0;
}