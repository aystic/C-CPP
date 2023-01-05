/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 01:43:55
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 01:48:00
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

void eraseIthBit(int n, int i) {
	// int mask = INT_MAX << i;
	int mask = ~(1 << i - 1);
	cout << (n & mask) << endl;
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

	int n, i;
	cin >> n >> i;
	eraseIthBit(n, i);
	return 0;
}