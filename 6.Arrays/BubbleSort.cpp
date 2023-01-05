/*
* @Author: pmohit
* @Date:   2021-06-08 12:33:20
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-08 17:28:34
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void Bubble_sort(int arr[], int n) {
	//do the pairwise swapping
	for (int itr = 1; itr <= n - 1; itr++) {
		for (int j = 0; j <= n - itr - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
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
	Bubble_sort(arr, 10);
	display(arr, 10);

	return 0;
}