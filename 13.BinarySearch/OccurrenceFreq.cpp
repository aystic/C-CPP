/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 00:51:56
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 00:56:31
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int arr[] {1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 12};
	int n = sizeof(arr) / sizeof(int);
	int key;
	cin >> key;
	bool present = binary_search(arr, arr + n, key);
	if (present)
		cout << "present" << endll;
	else
		cout << "absent" << endll;
	auto lb = lower_bound(arr, arr + n, key);
	auto ub = upper_bound(arr, arr + n, key);
	cout << "The Lower bound of " << key << " is " << lb - arr << endll;
	cout << "The Upper bound of " << key << " is " << ub - arr << endll;
	cout << "Occurence freq of " << key << " is " << ub - lb << endll;
	return 0;
}