/*
* @Author: Mohit Pathak
* @Date:   2021-06-18 20:05:26
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-18 20:26:22
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

//BRUTE FORCE APPROACH
void Bruteforce(int **arr, int row, int col) {
	int queries = 0;
	cin >> queries;
	while (queries--) {
		int tli, tlj, bri, brj;
		cin >> tli >> tlj >> bri >> brj;
		int sum = 0;
		for (int i = tli; i <= bri; ++i)
		{
			for (int j = tlj; j <= brj; ++j)
			{
				sum += arr[i][j];
			}
		}
		cout << sum << endl;
	}

}

void MakePrefixArray(int **arr, int row, int col) {
	//SUM ROW WISE
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (j != 0)
				arr[i][j] += arr[i][j - 1];
		}
	}
	//SUM COL WISE
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			if (i != 0)
				arr[i][j] += arr[i - 1][j];
		}
	}
}

void OptimisedApproach(int **arr, int row, int col) {
	int queries;
	cin >> queries;
	while (queries--) {
		int tli, tlj, bri, brj;
		cin >> tli >> tlj >> bri >> brj;
		int sum = 0;
		if (tli == 0 and tlj == 0) {
			sum += arr[bri][brj];
		} else if (tli != 0 and tlj != 0) {
			sum += arr[bri][brj] - arr[tli - 1][brj] - arr[bri][tlj - 1] + arr[tli - 1][tlj - 1];
		}
		else if (tlj != 0) {
			sum += arr[bri][brj] - arr[bri][tlj - 1];
		} else {
			sum += arr[bri][brj] - arr[tli - 1][brj];
		}
		cout << sum << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int row, col;
	cin >> row >> col;
	int ** arr = new int*[row];
	for (int i = 0; i < row; ++i)
	{
		arr[i] = new int[col];
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> arr[i][j];
		}
	}
	// Bruteforce(arr, row, col);
	MakePrefixArray(arr, row, col);
	OptimisedApproach(arr, row, col);
	return 0;
}