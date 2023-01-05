/*
* @Author: Mohit Pathak
* @Date:   2021-07-03 02:03:45
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-03 10:01:07
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int findGCD(int a, int b) {
	return b == 0 ? a : findGCD(b, a % b);
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
	int gcd = findGCD(a, b);
	int lcm = (a * b) / gcd;
	cout << lcm << " " << gcd << endl;
	return 0;
}