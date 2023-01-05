/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 01:19:43
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 01:35:26
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

bool findIthBit(int n, int i) {
	int mask = 1 << (i - 1);
	return (n & mask);
}

void printBits(int n) {
	int mask = INT_MAX;
	int count = 32;
	while (count) {
		mask = 1 << (count - 1);
		if (findIthBit(n, count)) {
			cout << 1;
		} else {
			cout << 0;
		}
		count--;
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

	int n, i;
	cin >> n >> i;
	if (findIthBit(n, i)) {
		cout << i << "th bit is on" << endl;
	} else {
		cout << i << "th bit if off" << endl;
	}
	printBits(n);
	return 0;
}