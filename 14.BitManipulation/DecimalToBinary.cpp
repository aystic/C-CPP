/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 22:44:20
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 22:51:03
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

//METHOD ONE
bool findIthBit(int n, int i) {
	int mask = 1 << (i - 1);
	return (n & mask);
}
void printBits(int n) {
	int mask = INT_MAX;
	int count = 32;
	bool flag = false;
	while (count) {
		mask = 1 << (count - 1);
		if (findIthBit(n, count)) {
			cout << 1;
			flag = true;
		} else {
			if (flag)
				cout << 0;
		}
		count--;
	}
}

//MEHTOD TWO
void DecimaltoBinary(int n) {
	long long unsigned int ans = 0;
	int power = 1;
	while (n) {
		ans += power * (n & 1);
		power *= 10;
		n = n >> 1;
	}
	cout << ans << endl;
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

	int n;
	cin >> n;
	printBits(n);
	cout << endl;
	DecimaltoBinary(n);
	cout << endl;
	return 0;
}