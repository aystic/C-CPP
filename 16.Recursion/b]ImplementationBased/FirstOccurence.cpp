/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 13:12:54
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 13:17:15
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int firstOccurence(int arr[], int start, int n, int key) {
	if (start == n)return -1;
	if (arr[start] == key)return start;
	return firstOccurence(arr, start + 1, n, key);
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
	cout << firstOccurence(arr, 0, n, key) << endl;
	return 0;
}