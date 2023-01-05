/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 02:49:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 02:55:23
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void clearLastIBits(int &n, int i) {
	int mask = (~(0) << i);
	n = (n & mask);

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
	clearLastIBits(n, i);
	cout << n << endl;
	return 0;
}