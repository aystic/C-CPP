/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-28 11:21:13
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-28 11:33:22
*/

#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


void waveSort(int arr[], int n) {
	for (int i = 1; i < n; i += 2)
	{
		if (arr[i] > arr[i - 1]) {
			swap(arr[i], arr[i - 1]);
		}
		if (i + 1 <= n - 1 and arr[i] > arr[i + 1]) {
			swap(arr[i], arr[i + 1]);
		}
	}
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
	waveSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
	return 0;
}
