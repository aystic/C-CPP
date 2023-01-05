/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 01:37:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 01:53:54
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int power(int a, int b) {
	if (b == 0)return 1;
	return a * power(a, b - 1);
}

int fastPower(int a, int b) {
	if (b == 0)return 1;
	int ans = fastPower(a, b / 2);
	ans *= ans;
	if (b & 1)
		return a * ans;
	else
		return ans;
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int a, b;
	cin >> a >> b;
	cout << power(a, b) << endll;
	cout << fastPower(a, b) << endll;
	return 0;
}