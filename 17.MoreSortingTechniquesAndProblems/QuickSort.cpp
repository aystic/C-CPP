/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-28 00:51:47
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-28 08:47:35
*/


#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(int arr[], int s, int e) {
	for (int i = s; i <= e; i++) {
		cout << arr[i] << " ";
	}
	cout << endll;
}

int partition(int arr[], int s, int e) {
	// int pivot = arr[e], i = s, j = e - 1;
	// while (true) {
	// 	if (i == j)break;
	// 	while (i < j and arr[i] <= pivot) {
	// 		i++;
	// 		if (i == j)break;
	// 	}
	// 	while (i<j and arr[j]>pivot) {
	// 		j--;
	// 		if (i == j)break;
	// 	}
	// 	swap(arr[i], arr[j]);
	// }
	// if (arr[i] > arr[e]) {
	// 	swap(arr[i], arr[e]);
	// }
	// return i;
	int pivot = arr[e], i = s - 1;
	for (int j = s; j < e; ++j)
	{
		if (arr[j] <= pivot) {
			swap(arr[++i], arr[j]);
		}
	}
	swap(arr[++i], arr[e]);
	return i;
}



void quickSort(int arr[], int s, int e) {
	if (s >= e) {
		return;
	}
	int pivotIndex = partition(arr, s, e);
	quickSort(arr, s, pivotIndex - 1);
	quickSort(arr, pivotIndex + 1, e);
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
	quickSort(arr, 0, n - 1);
	display(arr, 0, n - 1);
	return 0;
}