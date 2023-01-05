/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 10:46:39
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-08 10:54:04
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool IsSorted(int arr[], int start, int n) {
	if (start == n - 1 )return true;
	if (arr[start] > arr[start + 1])return false;
	return IsSorted(arr, start + 1, n);

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
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	if (IsSorted(arr, 0, n)) {
		cout << "Yes" << endll;
	} else {
		cout << "No" << endll;
	}
	return 0;
}