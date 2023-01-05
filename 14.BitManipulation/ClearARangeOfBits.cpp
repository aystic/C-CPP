/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 02:56:15
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 03:40:06
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void clearRangeOfBits(int& n, int i, int j) {
	int mask = (~(0) << i) | (~(~(0) << (j - 1)));
	n = n & mask;
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

	int n, i, j;
	cin >> n >> i >> j;
	clearRangeOfBits(n, i, j);
	cout << n << endl;
	return 0;
}