/*
* @Author: Mohit Pathak
* @Date:   2021-08-26 13:49:07
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 14:42:11
*/


#include<iostream>
#include<cmath>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(int arr[][100], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int k = 0; k < n; ++k)
		{
			cout << arr[i][k] << " ";
		}
		cout << endll;
	}
	cout << endll;
}

bool checkPlacement(int arr[][100], int n, int row, int col, int count) {
	//checking for row and col
	for (int i = 0; i < n; ++i)
	{
		if (arr[i][col] == count || arr[row][i] == count) {
			return false;
		}
	}
	//checking for sub-sudoku
	int size = sqrt(n);
	int sx = (row / size) * size, sy = (col / size) * size;
	for (int i = sx; i < sx + size; ++i)
	{
		for (int j = sy; j < sy + size; ++j)
		{
			if (arr[i][j] == count) {
				return false;
			}
		}
	}
	return true;

}


bool solveSudoku(int arr[][100], int n, int row, int col) {
	if (row == n) {
		display(arr, n);
		return true;
	}
	if (col == n) {
		return solveSudoku(arr, n, row + 1, 0);
	}
	if (arr[row][] != 0) {
		return solveSudoku(arr, n, row, col + 1);
	}
	for (int count = 1; count < 10; ++count)
	{
		bool isAllowed = checkPlacement(arr, n, row, col, count);
		if (isAllowed) {
			arr[row][col] = count;
			bool canSolve = solveSudoku(arr, n, row, col + 1);
			if (canSolve) {
				return true;
			}
		}
	}
	arr[row][col] = 0;
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
	int arr[100][100] {};
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	solveSudoku(arr, n, 0, 0);
	return 0;
}