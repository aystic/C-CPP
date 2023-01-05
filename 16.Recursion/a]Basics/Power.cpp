/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 13:00:39
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 13:01:44
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
	return b == 0 ? 1 : a * power(a, b - 1);
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
	cout << power(a, b) << endl;
	return 0;
}