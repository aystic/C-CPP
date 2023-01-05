/*
* @Author: pmohit
* @Date:   2021-06-08 12:33:20
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-08 17:09:30
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void selection_sort(int arr[], int n) {
	//find the min so far and then swap
	for (int i = 0; i < n - 1; ++i)
	{
		int minindex = i;
		for (int j = i; j < n; ++j)
		{
			if (arr[j] < arr[i]) {
				minindex = j;
			}
		}
		swap(arr[i], arr[minindex]);
	}

}

void display(int arr[], int n) {
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//--------------------------------------

	int arr[10];
	int count = 10;
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = count;
		count--;
	}
	display(arr, 10);
	selection_sort(arr, 10);
	display(arr, 10);

	return 0;
}