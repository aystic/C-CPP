/*
* @Author: Mohit Pathak
* @Date:   2021-06-25 02:29:59
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-25 02:38:24
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool ispossible(int arr[], int n, int m, int curr_min) {
	int studentused = 1;
	int pagesReading = 0;
	for (int i = 0; i < n; ++i)
	{
		if (pagesReading + arr[i] > curr_min) {
			studentused++;
			pagesReading = arr[i];
			if (studentused > m) {
				return false;
			}
		} else {
			pagesReading += arr[i];
		}
	}
	return true;
}



int findpages(int arr[], int n, int m) {
	int sum = 0;
	if (n < m) {
		return -1;
	}
	int ans = INT_MAX;
	for (int i = 0; i < n; ++i)
	{
		sum += arr[i];
	}
	int s = arr[n - 1], e = sum;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (ispossible(arr, n, m, mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		} else {
			s = mid + 1;
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

	int t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << findpages(arr, n, m) << endl;
	}

	return 0;
}