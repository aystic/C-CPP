/*
* @Author: Mohit Pathak
* @Date:   2021-05-27 03:50:25
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 03:58:22
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

	int i = 10;
label :
	cout << i << endll;//this is a label
	i--;
	if (i > 0)
		goto label;

	cout << endl;
	//switch statements also use labels
	int j;
	cin >> j;
	switch (j) {
	case 1:
		cout << "case1" << endll;
		break;
	default:
		cout << "wrong choice" << endll;
	}
	return 0;
}