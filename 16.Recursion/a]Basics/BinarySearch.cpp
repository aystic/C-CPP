/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 12:51:22
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 12:55:37
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int binarySearch(int arr[], int start, int end, int key) {
	if (start > end) {
		return -1;
	}
	int mid = (start + end) / 2;
	if (key == arr[mid]) {
		return mid;
	} else if (key < arr[mid]) {
		return binarySearch(arr, start, mid - 1, key);
	} else {
		return binarySearch(arr, mid + 1, end, key);
	}
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int n, key;
	cin >> n >> key;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << binarySearch(arr, 0, n - 1, key) << endl;
	return 0;
}