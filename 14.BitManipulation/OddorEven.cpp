/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 01:11:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 01:19:13
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool findEvenOrOdd(int n) {
	return !(n & 1);
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
	if (findEvenOrOdd(n)) {
		cout << "The no is even" << endl;
	} else {
		cout << "The no is odd" << endl;
	}
	return 0;
}