/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 13:02:05
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 13:03:26
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int multiply(int a, int b) {
	return b == 1 ? a : a + multiply(a, b - 1);
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
	cout << multiply(a, b) << endl;
	return 0;
}