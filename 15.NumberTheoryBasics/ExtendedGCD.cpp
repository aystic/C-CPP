/*
* @Author: Mohit Pathak
* @Date:   2021-07-03 09:50:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-03 12:49:59
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int extendedGCD(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}
	int x1, y1;
	int gcd = extendedGCD(b % a, a, &x1, &y1);
	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
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

	int a, b;
	cin >> a >> b;
	int x, y;
	int gcd = extendedGCD(a, b, &x, &y);
	cout << gcd << endl;
	cout << x << " " << y << endl;
	return 0;
}