/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 01:17:39
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 02:01:08
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int* upperbound(int*start, int* end, int key) {
	int *ans = 0;
	int s = 0, e = (end - start) - 1, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (*(start + mid) == key) {
			ans = start + mid;
			s = mid + 1;
		} else if (*(start + mid) > key) {
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	if (ans) {
		ans += 1;
	} else {
		if (s == mid) {
			ans = start + mid;
		} else if (e == mid) {
			ans = start + mid + 1;
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

	int arr[] {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int t;
	cin >> t;
	while (t--) {
		int key;
		cin >> key;
		int n = sizeof(arr) / sizeof(int);
		auto it = upperbound(arr, arr + n, key);
		if ((it - arr) == n) {
			cout << "Element not present" << endll;
		} else {
			cout << "Upper bound of " << key << " is " << it - arr << endl;
			cout << arr[it - arr] << endll;
		}
	}
	return 0;
}