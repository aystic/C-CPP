/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 11:07:57
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 11:11:06
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int countBinaryStrings(int n) {
	if (n == 0)return 1;
	if (n == 1)return 2;
	int x = countBinaryStrings(n - 1);
	int y = countBinaryStrings(n - 2);
	return x + y;
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
	cout << countBinaryStrings(n) << endl;
	return 0;
}
