/*
* @Author: Mohit Pathak
* @Date:   2021-07-10 11:14:13
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 11:25:46
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int towerOfHanoi(int n, int s, int e, int m) {
	if (n == 1) {
		cout << "Move one disc from " << s << " --> " << e << endl;
		return 1;
	}
	int x = towerOfHanoi(n - 1, s, m, e);
	int y = towerOfHanoi(1, s, e, m);
	int z = towerOfHanoi(n - 1, m, e, s);
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
	int steps = towerOfHanoi(n, 1, 3, 2);
	cout << "Total steps required are " << steps << endl;
	return 0;
}