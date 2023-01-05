/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 10:27:55
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 10:29:20
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int NthFibonacci(int n) {
	if (n == 1)return 0;
	if (n == 2)return 1;
	return NthFibonacci(n - 1) + NthFibonacci(n - 2);
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
	cout << NthFibonacci(n) << endl;
	return 0;
}