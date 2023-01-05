/*
* @Author: Mohit Pathak
* @Date:   2021-07-01 02:10:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 02:22:26
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int findSetBit(int xorResult) {
	int ans = -1;
	int count = 1;
	while (ans == -1) {
		if (xorResult & 1) {
			ans = count;
			return ans;
		} else {
			xorResult = xorResult >> 1;
			count++;
		}
	}
	return ans;
}

void findUniqueNo(int arr[], int n) {
	int xorResult = 0;
	for (int i = 0; i < n; ++i)
	{
		xorResult = arr[i] ^ xorResult;
	}
	int i = findSetBit(xorResult);
	int numone = 0, numtwo = 0;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i] & (1 << i - 1)) {
			numone = numone ^ arr[i];
		}
	}
	numtwo = xorResult ^ numone;
	if (numone < numtwo) {
		cout << numone << " " << numtwo << endl;
	} else {
		cout << numtwo << " " << numone << endl;
	}
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

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	findUniqueNo(arr, n);
	return 0;
}