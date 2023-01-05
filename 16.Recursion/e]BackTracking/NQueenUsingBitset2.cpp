/*
* @Author: Mohit Pathak
* @Date:   2021-08-26 14:24:46
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-26 15:59:15
*/


#include<iostream>
#include<bitset>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
bitset<20> colcheck, leftdiag, rightdiag;

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

bool solveNQueen(int arr[][20], int n, int row) {
	if (row == n) {
		display(arr, n);
		return true;
	}
	int col = 0;
	for (col = 0; col < n; ++col)
	{
		if (!colcheck[col] and !leftdiag[(col - row) + n] and !rightdiag[row + col]) {
			colcheck[col] = leftdiag[(col - row) + n] = rightdiag[row + col] = 1;
			arr[row][col] = 1;
			bool canplace = solveNQueen(arr, n, row + 1);
			if (canplace) {
				return true;
			}
			arr[row][col] = 0;
			colcheck[col] = leftdiag[(col - row) + n] = rightdiag[row + col] = 0;


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
	int arr[20][20]	{};
	solveNQueen(arr, n, 0);
	return 0;
}
