/*
* @Author: Mohit Pathak
* @Date:   2021-04-20 10:18:27
* @Last Modified by:  Mohit Pathak
* @Last Modified time: 2021-04-20 10:35:29
*/

//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//======================================
#define endll "\n"

//======================================

int size, count;

void display(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
}

void generate(int *arr, int n) {
	if (n == 0) {
		display(arr, size);
		count++
		;
	} else {
		arr[0] = 0;
		generate(arr + 1, n - 1);
		arr[0] = 1;
		generate(arr + 1, n - 1);

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
	generate(arr, n);
	cout << "Total strings generated : " << count << endll;
	return 0;
}