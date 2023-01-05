/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 01:57:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 06:40:12
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void bubbleSort_rec(int arr[], int n) {
	if (n == 1)return;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i + 1] < arr[i])
			swap(arr[i + 1], arr[i]);
	}
	bubbleSort_rec(arr, n - 1);

}

void bubbleSort_Loop(int arr[], int n) {
	for (int i = 1; i <= n - 1; ++i)
	{
		for (int j = 0; j <= n - 1 - i; ++j)
		{
			if (arr[j + 1] < arr[j]) {
				swap(arr[j + 1], arr[j]);
			}
		}
	}
}

void bubbleSort_recursive(int arr[], int j, int n) {
	if (n == 1)return;
	if (j == n - 2) {
		bubbleSort_recursive(arr, 0, n - 1);
		return ;
	}
	if (arr[j] > arr[j + 1])
		swap(arr[j], arr[j + 1]);
	bubbleSort_recursive(arr, j + 1, n);
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
	bubbleSort_rec(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	bubbleSort_recursive(arr, 0, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	// bubbleSort_Loop(arr, n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;
	return 0;
}