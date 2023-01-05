/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 18:16:22
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 19:34:08
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

bool canPlacecows(llu arr[], llu stalls, llu cows, llu min_sep) {
	llu count = 1;
	llu lastcow = 0;
	for (int i = 1; i < stalls; ++i)
	{
		if (arr[i] - arr[lastcow] >= min_sep) {
			count++;
			lastcow = i;
			if (count == cows)
				return true;
		}

	}
	return false;
}



llu FindMaxMinSeparation(llu arr[], llu stalls, llu cows) {
	//APPLY BINARY SEARCH IN THE SEARCH SPACE 0-MAX DISTANCE
	llu ans = -1;
	llu s = 0, e = arr[stalls - 1] - arr[0], mid;
	while (s <= e) {
		mid = (s + e) / 2;
		bool ispossible = canPlacecows(arr, stalls, cows, mid);
		if (ispossible) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
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

	llu t;
	cin >> t;
	while (t--) {
		llu stalls, cows;
		cin >> stalls >> cows;
		llu arr[stalls];
		for (int i = 0; i < stalls; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + stalls);
		cout << FindMaxMinSeparation(arr, stalls, cows) << endl;
	}

	return 0;
}