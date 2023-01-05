/*
* @Author: Mohit Pathak
* @Date:   2021-06-30 03:32:46
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-30 03:44:44
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void makeSubstring(int &n, int m, int i, int j) {
	//STEP ONE IS TO CLEAR THE BITS IN THE GIVEN RANGE
	int mask_to_clear = (~(0) << i) | (~(~(0) << j - 1));
	n = n & mask_to_clear;
	int mask_to_set = m << j - 1;
	n = n | mask_to_set;
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

	int n, m, i, j;
	cin >> n >> m >> i >> j;
	i++;
	j++;
	makeSubstring(n, m, i, j);
	cout << n << endl;
	return 0;
}