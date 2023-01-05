/*
* @Author: Mohit Pathak
* @Date:   2021-04-20 10:36:09
* @Last Modified by:  Mohit Pathak
* @Last Modified time: 2021-04-20 10:40:55
*/

//#include <bits/stdc++.h>
#include <iostream>

using namespace std;
//======================================
#define endll "\n"

//======================================

int Multiply(int a, int b) {
	if (b == 1) {
		return a;
	}
	return a + Multiply(a, b - 1);
}



//=======================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//=======================================

	int a, b;
	cin >> a >> b;
	cout << Multiply(a, b) << endll;
	return 0;
}