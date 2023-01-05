/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 02:29:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 03:17:08
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


//METHOD ONE
int findElement(ll arr[], ll size, int index, ll key) {
	auto it = lower_bound(arr, arr + index, key) - arr;
	auto it1 = lower_bound(arr + index, arr + size, key) - arr - index;
	if (arr[it] != key and arr[index + it1] != key)
		return -1;
	else {
		if (arr[it] == key)
			return it;
		else
			return index + it1;
	}
}

//METHOD TWO
int findElementM2(ll arr[], ll size, ll key) {
	ll s = 0, e = size - 1, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] == key)
			return mid;
		else if (arr[s] <= arr[mid]) {
			//mid lies in the first part of the array
			if (key >= arr[s] and key <= arr[mid]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		} else if (arr[e] >= arr[mid]) {
			//mid lies in the second part of the array
			if (key <= arr[e] and key >= arr[mid])
				s = mid + 1;
			else
				e = mid - 1;
		}
	}
	return -1;

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

	ll size;
	cin >> size;
	ll arr[size] {};
	int index = -1;
	bool flag = true;
	for (int i = 0; i < size; ++i)
	{
		cin >> arr[i];
		if (i != 0 and arr[i - 1] > arr[i]) { //arr2
			index = i;
		}
	}
	ll key;
	cin >> key;
	// cout << findElement(arr, size, index, key);
	cout << findElementM2(arr, size, key) << endl;
	return 0;
}