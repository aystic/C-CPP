/*
* @Author: pmohit
* @Date:   2021-07-08 09:47:43
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 10:14:57
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int factorial(int n) {
	return n == 0 ? 1 : n * factorial(n - 1);
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	//======================================

	int n;
	cin >> n;
	cout << factorial(n) << endl;
	return 0;
}