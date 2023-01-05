/*
* @Author: Mohit Pathak
* @Date:   2021-07-01 04:17:36
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 04:35:08
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

//POWER OPTIMISED O(log(N))
int powerOptimised(int a, int b) {
	int answer = 1;
	while (b) {
		if (b & 1) {
			answer *= a;
		}
		b = b >> 1;
		a = (a * a);
	}
	return answer;
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

	int a, b;
	cin >> a >> b;
	cout << powerOptimised(a, b) << endl;
	return 0;
}