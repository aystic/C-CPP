/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 07:32:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 07:39:42
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int merge(int arr[], int s, int e) {
	int mid = (s + e) / 2;
	int i = s, j = mid + 1, k = s;
	int temp[100000];
	int count = 0;
	while (i <= mid and j <= e) {
		if (arr[i] < arr[j]) {
			temp[k++] = arr[i++];
		} else {
			temp[k++] = arr[j++];
			count += mid - i + 1;
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
	return count;
}

int inversionCount(int arr[], int s, int e) {
	if (s >= e)return 0;
	int mid = (s + e) / 2;
	int x = inversionCount(arr, s, mid);
	int y = inversionCount(arr, mid + 1, e);
	int z = merge(arr, s, e);
	return x + y + z;
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
	cout << inversionCount(arr, 0, n - 1) << endl;
	return 0;
}