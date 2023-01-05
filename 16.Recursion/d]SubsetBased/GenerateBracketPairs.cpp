/*
* @Author: Mohit Pathak
* @Date:   2021-07-11 00:23:19
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-11 00:35:31
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void generateBracketPairs(char output[], int n, int i, int countOpening, int countClosing) {
	if (i == 2 * n) {
		output[i] = '\0';
		cout << output << endl;
		return;
	}
	if (countOpening < n) {
		output[i] = '(';
		generateBracketPairs(output, n, i + 1, countOpening + 1, countClosing);
	}
	if (countClosing < countOpening) {
		output[i] = ')';
		generateBracketPairs(output, n, i + 1, countOpening, countClosing + 1);
	}
	return;
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
	char output[100];
	generateBracketPairs(output, n, 0, 0, 0);
	return 0;
}