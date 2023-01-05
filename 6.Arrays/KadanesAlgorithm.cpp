/*
* @Author: Mohit Pathak
* @Date:   2021-06-09 11:56:19
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-09 11:59:04
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<climits>

using namespace std;
#define endll '\n'
//--------------------------------------

void kadanes_algo(int arr[], int n) {
	int maxsum = INT_MIN, currentsum = 0;
	for (int i = 0; i < n; ++i)
	{
		currentsum += arr[i];
		if (currentsum < 0)
			currentsum = 0;
		if (currentsum > maxsum)
			maxsum = currentsum;
	}
	cout << "The max subarray sum is " << maxsum << endll;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	kadanes_algo(arr, n);
	return 0;
}