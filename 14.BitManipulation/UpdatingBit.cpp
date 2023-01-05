/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 01:49:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 02:40:46
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void UpdateIthBitToV(int& n, int i, int v) {
	int mask;
	if (v) { //IF V IS 1 DO OR OPERATION 0001000
		mask = 1 << (i - 1);
		n = n | mask;
	} else { //IF V IS 0 DO AND OPERATION 1110111
		mask = ~(1 << (i - 1));
		n = n & mask;
	}
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

	int n, i, v;
	cin >> n >> i >> v;
	UpdateIthBitToV(n, i, v);
	cout << n << endl;
	return 0;
}