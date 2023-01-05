/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 05:30:34
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 10:30:07
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================



int PossibleWays(int n) {
	if (n <= 0)return 0;
	if (n < 4)return 1;
	if (n == 4)return 2;
	else {
		int x = PossibleWays(n - 1);
		int y = PossibleWays(n - 4);
		return x + y;
	}
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
	cout << PossibleWays(n) << endl;
	return 0;
}