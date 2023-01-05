/*
* @Author: Mohit Pathak
* @Date:   2021-06-17 14:06:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-17 23:46:56
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------
void SumOfAllSubarrays(int ** arr, int row, int col) {
	int sum = 0;
	for (int tli = 0; tli < row; ++tli)
	{
		for (int tlj = 0; tlj < col; ++tlj)
		{
			for (int bri = tli; bri < row; ++bri)
			{
				for (int brj = tlj; brj < col; ++brj)
				{
					int upper = 0, left = 0, upperleft = 0;
					if (tli - 1 >= 0) {
						upper = arr[tli - 1][brj];
					}
					if (tlj - 1 >= 0) {
						left = arr[bri][tlj - 1];
					}
					if (tli - 1 >= 0 and tlj >= 0) {
						upperleft = arr[tli - 1][tlj - 1];
					}
					sum += arr[bri][brj] - upper - left + upperleft;
				}
			}
		}
	}
	cout << sum << endl;

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
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cin >> arr[i][j];
			if (j != 0)
				arr[i][j] += arr[i][j - 1];
		}
	}
	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			if (j != 0)
				arr[j][i] += arr[j - 1][i];
		}
	}
	SumOfAllSubarrays(arr, row, col);
	return 0;
}