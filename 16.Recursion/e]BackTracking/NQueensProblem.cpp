/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-25 17:27:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 06:47:45
*/

#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(int arr[][20], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == 1)cout << "Q ";
			else cout << "_ ";
		}
		cout << endll;
	}
	cout << endll;
}

bool checkPlacement(int arr[][20], int n, int row, int col) {
	int i, j;
	//left diagonal
	i = row - 1, j = col - 1;
	while (i >= 0 and j >= 0) {
		if (arr[i][j] == 1) {
			return false;
		}
		i--;
		j--;
	}
	//right diagonal
	i = row - 1, j = col + 1;
	while (i >= 0 and j < n) {
		if (arr[i][j] == 1) {
			return false;
		}
		i--;
		j++;
	}
	//column
	i = row - 1;
	while (i >= 0) {
		if (arr[i][col] == 1) {
			return false;
		}
		i--;
	}
	//row
	for (int i = 0; i < n; ++i)
	{
		if (i != col and arr[row][i] == 1) {
			return false;
		}
	}
	return true;
}

bool solveNQueen(int arr[][20], int n, int row, int &count) {
	if (row == n) {
		display(arr, n);
		count++;
		return false;
	}
	bool possible = false;
	for (int i = 0; i < n; ++i)
	{
		arr[row][i] = 1; //placing the queen
		bool canPlace = checkPlacement(arr, n, row, i);
		if (canPlace and solveNQueen(arr, n, row + 1, count)) {
			return true;
		}
		arr[row][i] = 0;
	}
	return false;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	int arr[20][20] {};
	int count = 0;
	solveNQueen(arr, n, 0, count);
	cout << "No of possible configs " << count << endll;
	return 0;
}