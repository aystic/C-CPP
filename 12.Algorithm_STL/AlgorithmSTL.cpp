/*
* @Author: Mohit Pathak
* @Date:   2021-06-21 17:46:02
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-21 23:36:35
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool compare(int, int);
bool comparelb(int, int );
bool compareub(int , int );

//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	//PAIR
	pair<int, pair<string, string>> details;//DOESNOT REQUIRE THE ALGORITHM HEADER
	details.first = 999;
	details.second.first = "Mohit";
	details.second.second = "Pathak";

	cout << "The age is :" << details.first << endll;
	cout << "The name is : " << details.second.first << " " << details.second.second << endl;
	// int arr[] {3, 4, 9, 11, 112, 55, 0};
	// int size = sizeof(arr) / sizeof(int);
	// for (int i = 0; i < size; ++i)
	// {
	// 	cout << arr[i] << " ";
	// }
	// cout << endl;


	// //AUTO IT=FIND(ARR,ARR+N,KEY);
	// cout << "Using Find Function: " << endll;
	// auto it = find(arr, arr + size, 11);
	// cout << it << " " << &arr[3] << endll;
	// cout << *it << " " << arr[3] << endll;
	// // it = find(arr, arr + size, 999);
	// // cout << it << " " << &arr[size] << endll;
	// // cout << *it << " " << arr[size] << endll;
	// cout << "The index of the found object is: " << it - arr << endll;

	// //BOOL ISPRESENT=BINARY_SEARCH(ARR,ARR+N,KEY)
	// cout << "Using the binary search:" << endll;
	// bool ispresent = binary_search(arr, arr + size, 999);
	// if (ispresent) {
	// 	cout << "Present" << endll;
	// } else {
	// 	cout << "Not Present" << endll;
	// }


	// //LOWER AND UPPER BOUND
	// int arr1[] {1, 2, 5, 10, 15, 25, 50, 100, 150, 200};
	// int n = sizeof(arr1) / sizeof(int);
	// cout << "Using lower bound and upper bound:" << endll;
	// auto lb = lower_bound(arr1, arr1 + n, 100) - arr1;
	// auto lb1 = lower_bound(arr1, arr1 + n, 115) - arr1;
	// auto lb2 = lower_bound(arr1, arr1 + n, 100, comparelb) - arr1;
	// auto lb3 = lower_bound(arr1, arr1 + n, 115, comparelb) - arr1;
	// cout << lb << " " << lb1 << endll;
	// cout << lb2 << " " << lb3 << endll;

	// auto ub = upper_bound(arr1, arr1 + n, 100) - arr1 - 1;
	// cout << arr1[ub] << endl;


	int arr2[] {5, 9, 8, 1, 2, 4, 3, 6};
	int n = sizeof(arr2) / sizeof(int);
	sort(arr2, arr2 + n, compare);
	for (int i = 0; i < n; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	rotate(arr2, arr2 + 7, arr2 + n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	next_permutation(arr2, arr2 + 8);
	for (int i = 0; i < n; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	reverse(arr2, arr2 + n);
	for (int i = 0; i < n; ++i)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	return 0;
}

bool comparelb(int a, int b) {
	return a <= b;
}
bool compareub(int a, int b);

bool compare(int a, int b) {
	return a > b;
}
