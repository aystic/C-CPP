/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 06:49:43
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 07:06:30
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void merge(int arr[], int s, int mid, int e) {
	int i = s, j = mid + 1, k = s;
	int temp[100];
	while (i <= mid and j <= e) {
		if (arr[i] < arr[j]) {
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
	return;
}


void mergeSort(int arr[], int s, int e) {
	//BASE CASE
	if (s >= e)return;

	//DIVIDE AND SORT THE ARRAY ALONG THE MID POINT
	int mid = (s + e) / 2;
	mergeSort(arr, s, mid);
	mergeSort(arr, mid + 1, e);
	//MERGE THE SORTED ARRAYS INTO AN ARRAY
	merge(arr, s, mid, e);
	return;
}

//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
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
	cout << endl;
	return 0;
}