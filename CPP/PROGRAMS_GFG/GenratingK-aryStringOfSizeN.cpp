/*
* @Author: Mohit Pathak
* @Date:   2021-04-20 04:27:24
* @Last Modified by:  Mohit Pathak
* @Last Modified time: 2021-04-20 04:32:27
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
		count++;
	}
	cout << endll;
}

void k_ary(int *arr, int n, int k) {
	if (n < 1) {
		display(arr, size);
	} else {
		for (int i = 1; i <= k; ++i)
		{
			arr[n - 1] = i;
			k_ary(arr, n - 1, k);
		}
	}
}


//=======================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//=======================================

	int n, k;
	cin >> n >> k;
	size = n;
	int arr[n];
	k_ary(arr, n, k);
	cout << "Total strings : " << count << endll;
	return 0;
}