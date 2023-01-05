/*
* @Author: Mohit Pathak
* @Date:   2021-06-19 00:01:13
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-19 00:19:04
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<climits>
using namespace std;
#define endll '\n'
//--------------------------------------

void makeSuffixArray(int **arr, int row, int col) {
	//ADDING ROWS IN REVERSE
	for (int i = row - 1; i >= 0; --i)
	{
		for (int j = col - 1; j >= 0; --j)
		{
			if (j != col - 1)
				arr[i][j] += arr[i][j + 1];
		}
	}
	//ADDING COLS IN REVERSE
	for (int i = col - 1; i >= 0; --i)
	{
		for (int j = row - 1; j >= 0; --j)
		{
			if (j != row - 1)
				arr[j][i] += arr[j + 1][i];
		}
	}
}


void findMaxSubarraySum(int **arr, int row, int col) {
	int max = INT_MIN;
	int imax, jmax;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (arr[i][j] > max) {
				imax = i;
				jmax = j;
				max = arr[i][j];
			}
		}
	}
	cout << "The max sum is " << max << endl;
	cout << "Max Subarray : ";
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------
	int row, col;
	cin >> row >> col;
	int **arr = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		arr[i] = new int[col];
	}
	//ARRAY INPUT
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> arr[i][j];
		}
	}
	makeSuffixArray(arr, row, col);
	findMaxSubarraySum(arr, row, col);

	return 0;
}