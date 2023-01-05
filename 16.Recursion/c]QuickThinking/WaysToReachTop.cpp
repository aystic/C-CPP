/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 05:58:29
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 06:07:51
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//==========================================

int findWays(int n) {
	if (n < 0)return 0;
	if (n == 1 or n == 0)return 1;
	// if (n == 2)return 2;
	// if (n == 3)return 4;
	int x = findWays(n - 1);
	int y = findWays(n - 2);
	int z = findWays(n - 3);
	return x + y + z;
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int n;
	cin >> n;
	cout << findWays(n) << endl;
	return 0;
}