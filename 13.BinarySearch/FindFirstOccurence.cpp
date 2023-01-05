/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 00:31:23
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 00:43:03
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int FindFirstOccurence(int arr[], int n, int key) {
	int ans = -1;
	int start = 0, end = n - 1;
	while (start <= end) {
		int mid = (start + end) / 2;
		if (arr[mid] == key) {
			ans = mid;
			end = mid - 1;
		} else if (arr[mid] > key) {
			end = mid - 1;
		} else {
			start = mid + 1;
		}
	}
	return ans;
}

int FindLastOccurence(int arr[], int n, int key) {
	int ans = -1;
	int start = 0, end = n - 1, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		if (arr[mid] == key) {
			ans = mid;
			start = mid + 1;
		} else if (arr[mid] < key) {
			start = mid + 1;
		} else {
			end = mid - 1;
		}
	}
	return ans;
}

//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int arr[] {1, 2, 3, 4, 5, 6, 8, 8, 8, 9 , 10, 11, 16, 17};
	int n = sizeof(arr) / sizeof(int);
	int key;
	cin >> key;
	int index = FindFirstOccurence(arr, n, key);
	if (index == -1) {
		cout << "Element not found" << endll;
	} else {
		cout << "First occurence of " << key << " is at index " << index << endll;
	}
	index = FindLastOccurence(arr, n, key);
	if (index == -1) {
		cout << "Element not found" << endll;
	} else {
		cout << "Last occurence of " << key << " is at index " << index << endll;
	}
	return 0;
}