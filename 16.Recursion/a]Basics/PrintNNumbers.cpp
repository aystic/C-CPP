/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 10:36:56
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 10:42:15
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void increasingOrder(int n) {
	if (n == 0) {
		cout << n << " ";
		return ;
	}
	increasingOrder(n - 1);
	cout << n << " ";
}

void decreasingOrder(int n) {
	if (n == 0) {
		cout << 0 << endl;
		return;
	}
	cout << n << " ";
	decreasingOrder(n - 1);
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
	cout << "Increasing Order:" << endl;
	increasingOrder(n);
	cout << endll;
	cout << "Decreasing Order:" << endl;
	decreasingOrder(n);
	cout << endll;
	return 0;
}