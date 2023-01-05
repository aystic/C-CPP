/*
* @Author: Mohit Pathak
* @Date:   2021-06-08 18:47:23
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-09 11:51:39
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<climits>

using namespace std;
#define endll '\n'
//--------------------------------------

//Method one
void findmaxsumM1(int arr[], int n) {
	int maxsum = INT_MIN;
	int start = -1, end = -1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{	int currentsum = 0;
			for (int k = i; k <= j; k++) {
				currentsum += arr[k];
			}
			if (currentsum > maxsum) {
				maxsum = currentsum;
				start = i;
				end = j;
			}
		}
	}
	cout << "The max sum is " << maxsum << " and the array is ";
	for (int i = start; i <= end; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
}

//Method two
void findmaxsumM2() {
	int n;
	cin >> n; //size of the array
	int cs[n] {};
	//forming the cummulative sum array
	for (int i = 0; i < n; ++i)
	{
		if (i == 0)
			cin >> cs[i];
		else {
			int temp;
			cin >> temp;
			cs[i] = cs[i - 1] + temp;
		}
	}
	//Finding the max sum
	int maxsum = INT_MIN;
	int start = -1, end = -1;
	for (int i = 0; i < n; ++i)
	{
		if (cs[i] > maxsum) {
			maxsum = cs[i];
			cout << cs[i] << " ";
		}
	}
	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			int currentsum;
			currentsum = cs[j] - cs[i - 1];
			if (currentsum > maxsum) {
				maxsum = currentsum;
			}
			cout << currentsum << " ";
		}
	}
	cout << endll;
	cout << "The max sum is " << maxsum << endll;
}

// int maxsum = INT_MIN;
// for (int i = 1; i <= n; ++i)
// {
// 	for (int j = i - 1; j < n; ++j)
// 	{
// 		if (j - i != -1) {
// 			int currentsum = cs[j] - cs[j - i];
// 			if (currentsum > maxsum) {
// 				maxsum = currentsum;
// 			}
// 		}

// 		else {
// 			int currentsum = cs[j];
// 			if (currentsum > maxsum) {
// 				maxsum = currentsum;
// 			}
// 		}
// 	}
// }




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	// int arr[5] = { -2, 12, -5, 10, -3};
	// findmaxsumM1(arr, 5);
	findmaxsumM2();
	return 0;
}