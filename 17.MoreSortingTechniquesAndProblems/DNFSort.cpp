/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-28 10:46:28
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-28 11:19:00
*/


#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void dnfSort(int arr[], int n) {
	int low = 0, mid = 0, high = n - 1;
	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(arr[low++], arr[mid++]);
		} else if (arr[mid] == 2) {
			swap(arr[mid], arr[high--]);
		} else {
			mid++;
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
	dnfSort(arr, n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
	return 0;
}