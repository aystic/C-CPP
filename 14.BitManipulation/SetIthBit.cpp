/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 01:37:36
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 01:46:56
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void setIthBit(int n, int i) {
	int mask = 1 << (i - 1);
	n = (n | mask);
	cout << n << endl;
}



//==========================================b
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
	setIthBit(n, i);
	return 0;
}