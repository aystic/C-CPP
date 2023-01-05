/*
* @Author: pmohit
* @Date:   2021-06-30 01:04:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-01 09:51:14
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int findUniqueNo(int arr[], int n) {
	int answer = 0;
	for (int i = 0; i < n; ++i)
	{
		answer = answer ^ arr[i];
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

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << findUniqueNo(arr, n) << endl;
	return 0;
}