/*
* @Author: Mohit Pathak
* @Date:   2021-08-27 01:34:23
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-27 02:24:06
*/


#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int crossInversion(int arr[], int s, int mid, int e) {
	int temp[100];
	int i = s, j = mid + 1, k = s;
	int count = 0;
	while (i <= mid and j <= e) {
		if (arr[i] <= arr[j]) {
			temp[k++] = arr[i++];
		} else {
			count += (mid + 1 - i);
			temp[k++] = arr[j++];
		}
	}
	while (i <= mid) {
		// count += j - mid;
		temp[k++] = arr[i++];
	}
	while (j <= e) {
		temp[k++] = arr[j++];
	}
	for (int i = s; i <= e; ++i)
	{
		arr[i] = temp[i];
	}
	return count;
}


int inversionCount(int arr[], int s, int e) {
	if (s >= e) {
		return 0;
	}
	int mid = (s + e) / 2;
	int x = inversionCount(arr, s, mid);
	int y = inversionCount(arr, mid + 1, e);
	int z = crossInversion(arr, s, mid, e);
	return x + y + z;
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
	cout << inversionCount(arr, 0, n - 1) << endll;
	return 0;
}