/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 10:07:15
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 10:14:07
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int partition(int arr[], int s, int e) {
	int pivot = arr[e];
	int i = s - 1, j = s;
	while (j <= e - 1) {
		if (arr[j] < pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}
	swap(arr[++i], arr[e]);
	return i;
}


void quickSort(int arr[], int s, int e) {
	//BASE CASE
	if (s >= e)return;
	//DO PARTITION
	int pivot = partition(arr, s, e);
	//QUICKSORT
	quickSort(arr, s, pivot - 1);
	quickSort(arr, pivot + 1, e);
	return ;
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1) ;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}