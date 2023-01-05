/*
* @Author: pmohit
* @Date:   2021-06-11 00:52:39
* @Last Modified by:   pmohit
* @Last Modified time: 2021-06-11 01:00:02
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void staircaseSearch(int arr[100][100], int row, int col, int key) {
	int rp = 0, cp = col - 1;
	while (rp < row and cp >= 0) {
		if (key == arr[rp][cp]) {
			cout << "Key found at " << rp << " " << cp << endll;
			return;
		} else if (key > arr[rp][cp]) {
			rp++;
		} else {
			cp--;
		}
	}
	cout << "Element not found" << endll;
}


void display(int arr[100][100], int row, int col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << arr[i][j] << '\t';
		}
		cout << endll;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------


	int arr[100][100];
	int row, col, key;
	cin >> row >> col >> key;
	int count;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			arr[i][j] = count++;
		}
	}
	display(arr, row, col);
	staircaseSearch(arr, row, col, key);
	return 0;
}