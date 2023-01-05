/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-06 22:49:42
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-06 23:22:49
*/

#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool ascending = true;

bool compare(int a, int b) {
	if (!ascending) {
		return a > b;
	}
	return a < b;
}

void heapify(int arr[], int n, int idx) {
	int left = 2 * idx + 1;
	int right = left + 1;
	int replacingIndex = idx;
	if (left <= n and compare(arr[idx], arr[left])) {
		replacingIndex = left;
	}
	if (right <= n and compare(arr[replacingIndex], arr[right])) {
		replacingIndex = right;
	}
	if (replacingIndex != idx) {
		swap(arr[idx], arr[replacingIndex]);
		heapify(arr, n, replacingIndex);
	}
}


void heapSort(int arr[], int n, bool type = true) {
	n--;
	ascending = type;
	//converting the array into maxheap
	int idx;
	if (n & 1)idx = n / 2;
	else idx = (n - 1) / 2;
	for (int i = idx; i >= 0; --i) {
		heapify(arr, n, i);
	}
	//removing all the elements one by one
	for (int i = 0; i < n; i++) {
		swap(arr[0], arr[n - i]);
		heapify(arr, n - i - 1, 0);
	}
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int arr[] {13, 12, 10, 4, 2, 21, 22, 8, 7, 3, 2};
	int n = sizeof(arr) / sizeof(int);
	heapSort(arr, n, true);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
	return 0;
}