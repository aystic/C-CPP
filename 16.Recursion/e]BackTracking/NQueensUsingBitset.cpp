/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-25 17:27:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 07:16:06
*/

#include<iostream>
#include<bitset>

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

bool checkPlacement(int arr[][20], int n, int row, int col, bitset<20>&coltest, bitset<20>&leftdiag, bitset<20>&rightdiag) {
	if (coltest.test(col) or leftdiag.test((col - row) + n) or rightdiag.test(row + col + 1)) {
		return false;
	}
	return true;
}

bool solveNQueen(int arr[][20], int n, int row, int &count, bitset<20>&col, bitset<20>&leftdiag, bitset<20>&rightdiag) {
	if (row == n) {
		display(arr, n);
		count++;
		return false;
	}
	bool possible = false;
	for (int i = 0; i < n; ++i)
	{
		bool canPlace = checkPlacement(arr, n, row, i, col, leftdiag, rightdiag);
		if (canPlace) {
			arr[row][i] = 1; //placing the queen
			col.set(i, 1);
			leftdiag.set((i - row) + n, 1);
			rightdiag.set((row + i) + 1, 1);
			if (solveNQueen(arr, n, row + 1, count, col, leftdiag, rightdiag)) {
				return true;
			} else {
				arr[row][i] = 0;
				col.set(i, 0);
				leftdiag.set((i - row) + n, 0);
				rightdiag.set((row + i) + 1, 0);
			}
		}
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
	bitset<20> col;
	bitset<20> leftdiag;
	bitset<20> rightdiag;

	int arr[20][20] {};
	int count = 0;
	solveNQueen(arr, n, 0, count, col, leftdiag, rightdiag);
	cout << "No of possible configs " << count << endll;
	return 0;
}