/*
* @Author: Mohit Pathak
* @Date:   2021-07-01 02:39:04
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 03:39:02
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void findUniqueNumber(int arr[], int n) {
	int count[32] {};
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		j = 0;
		while (arr[i]) {
			count[j] += (arr[i] & 1);
			arr[i] = (arr[i] >> 1);
			j++;
		}
	}
	int number = 0, power = 1;
	for (int i = 0; i < 32; ++i)
	{
		count[i] %= 3;
		number += (power * count[i]);
		power = (power << 1);
	}
	cout << number << endl;
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
	findUniqueNumber(arr, n);
	return 0;
}