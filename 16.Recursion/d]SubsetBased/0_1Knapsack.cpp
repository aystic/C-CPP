/*
* @Author: Mohit Pathak
* @Date:   2021-07-11 00:40:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-11 03:24:17
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int findMaxValue(pair<int, int>arr[], int n, int c) {
	if (n == 0 or c == 0)return 0;
	int x = 0;
	if (c >= arr[n - 1].first) {
		x = findMaxValue(arr, n - 1, c - arr[n - 1].first);
		x += arr[n - 1].second;

	}
	int y = findMaxValue(arr, n - 1, c);
	return max(x, y);
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
	pair<int, int> arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i].first >> arr[i].second;
	}
	int c;
	cin >> c;
	cout << findMaxValue(arr, n, c) << endl;
	return 0;
}