/*
* @Author: Mohit Pathak
* @Date:   2021-06-06 04:23:45
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-06 04:28:41
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int n;
	cin >> n;
	float inc = 1;
	int precision;
	cin >> precision;
	float sr = 0;
	while (precision >= 0) {
		sr += inc;
		while (sr * sr <= n) {
			sr += inc;
		}
		sr -= inc;
		inc /= 10;
		precision--;
	}
	cout << sr << endll;

	return 0;
}