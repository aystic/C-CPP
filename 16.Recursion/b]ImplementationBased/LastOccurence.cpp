/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 23:10:15
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 23:12:17
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int lastOccurence(int arr[], int n, int key) {
	if (n == 0)return -1;
	if (arr[n - 1] == key)return n - 1;
	return lastOccurence(arr, n - 1, key);
}



//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int n, key;
	cin >> n >> key;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << lastOccurence(arr, n, key) << endll;
	return 0;
}