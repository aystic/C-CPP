/*
* @Author: Mohit Pathak
* @Date:   2021-07-03 12:59:30
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-03 13:26:55
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int extendedEculidian(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = extendedEculidian(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}


void findMMI(int a, int m) {
	int x, y;
	int gcd = extendedEculidian(a, m, &x, &y);
	if (gcd == 1) {
		cout << (x % m + m) % m << endl;
	} else {
		cout << "MMI doesn't exist" << endl;
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

	int a, m;
	cin >> a >> m;
	findMMI(a, m);
	return 0;
}