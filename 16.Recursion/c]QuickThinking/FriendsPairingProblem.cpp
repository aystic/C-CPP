/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 10:40:46
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 11:02:46
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


int findPairs(int n) {
	if (n < 0)return 0;
	if (n == 0 or n == 1)return 1;
	int x = findPairs(n - 1);
	int y = (n - 1) * findPairs(n - 2);
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
	cout << findPairs(n) << endll;
	return 0;
}