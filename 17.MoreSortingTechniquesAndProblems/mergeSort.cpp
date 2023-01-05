/*
* @Author: pmohit
* @Date:   2021-08-26 17:52:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 19:13:42
*/


#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void merge(int arr[], int s, int mid, int e) {
	int temp[100];
	int i = s, j = mid + 1, k = s;
	while (i <= mid and j <= e) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = arr[i++];
	}
	while (j <= e) {
		temp[k++] = arr[j++];
	}
	for (int i = s; i <= e; ++i)
	{
		arr[i] = temp[i];
	}
}

void mergeSort(int arr[], int s, int e) {
	if (s >=  e) {
		return;
	}
	int mid = (s + e) / 2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	merge(arr, s, mid, e);
	return;
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	mergeSort(arr, 0, n - 1);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
	return 0;
}