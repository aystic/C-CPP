/*
* @Author: Mohit Pathak
* @Date:   2021-07-01 14:41:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 22:59:29
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	int arr[1000000] {};
	for (int i = 3; i < 1000000; i += 2)arr[i] = 1;
	for (int i = 0; i < 1000; ++i)
	{
		if (arr[i] == 1) {
			for (int j = i * i; j < 1000000; j += i)
			{
				arr[j] = 0;
			}
		}
	}
	arr[1] = arr[0] = 0;
	arr[2] = 1;
	for (int i = 1; i < 1000000; ++i)
	{
		arr[i] += arr[i - 1];
	}
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		cout << arr[b] - arr[a - 1] << endl;
	}
	return 0;
}