/*
* @Author: Mohit Pathak
* @Date:   2021-06-22 03:55:27
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-22 04:00:43
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

float squareRoot(int n, int p) {
	float ans = -1;
	int s = 0, e = n, mid;
	while (s <= e) {
		mid = (s + e) / 2;
		if (mid * mid == n)
			return mid;
		else if (mid * mid > n) {
			e = mid - 1;
		} else {
			ans = mid;
			s = mid + 1;
		}
	}

	float inc = 0.1;
	for (int i = 0; i < p; ++i)
	{
		while (ans * ans <= n) {
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
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

	int n, p;
	cin >> n >> p;
	cout << squareRoot(n, p) << endl;
	return 0;
}