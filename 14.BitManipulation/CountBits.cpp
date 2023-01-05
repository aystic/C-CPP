/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 03:50:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 22:41:00
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
int countBits(int n) {
	int ans = 0;
	while (n) {
		ans += (n & 1);
		n = n >> 1;
	}
	return ans;
}

//METHOD TWO(FAST) O(no of set bits)
int countBitsFast(int n) {
	int ans = 0;
	while (n) {
		n = n & (n - 1);
		ans++;
	}
	return ans;
}

//MEHTOD THREE INBUILT FUNCTION __builtin_popcount(n)



//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	cout << countBits(n) << endl;
	cout << countBitsFast(n) << endl;
	cout << __builtin_popcount(n) << endl;
	return 0;
}