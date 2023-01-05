/*
* @Author: Mohit Pathak
* @Date:   2021-06-17 13:33:49
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-17 13:42:38
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void SumOfAllSubarrays(int**arr, int row, int col) {
	int sum = 0;
	//FINDING ALL THE TOP LEFT
	for (int tli = 0; tli < row; ++tli)
	{
		for (int tlj = 0; tlj < col; ++tlj)
		{
			//FINDING THE BOTTOM RIGHT
			for (int bri = 0; bri < row; ++bri)
			{
				for (int brj = 0; brj < col; ++brj)
				{
					//SUMMING ALL THE VALUES
					for (int i = tli; i <= bri; ++i)
					{
						for (int j = tlj; j <= brj; ++j)
						{
							sum += arr[i][j];
						}
					}
				}
			}
		}
	}
	cout << "Sum of all the subarrays is " << sum << endl;
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
		}
	}
	SumOfAllSubarrays(arr, row, col);
	return 0;
}