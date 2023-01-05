/*
* @Author: Mohit Pathak
* @Date:   2021-07-08 23:19:53
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-09 01:37:38
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int firstOccurence(int arr[], int n, int key) {
	if (n == 0)return -1;
	if (arr[0] == key)return 0;
	int i = firstOccurence(arr + 1, n - 1, key);
	return i == -1 ? -1 : i + 1;
}

int lastOccurence(int arr[], int n, int key) {
	if (n == 0)return -1;
	int i = lastOccurence(arr + 1, n - 1, key);
	if (i == -1) {
		if (arr[0] == key)
			return 0;
		else
			return -1;
	}
	return i + 1;
}

void alloccurence(int arr[], int start, int n, int key) {
	if (n == 0)return;
	if (arr[start] == key)
		cout << start << " ";
	alloccurence(arr, start + 1, n - 1, key);
}

int storeOccurences(int arr[], int i, int n, int j, int output[], int key) {
	if (n == 0)return j + 1;
	if (arr[i] == key) {
		output[++j] = i;
	}
	i += 1;
	return storeOccurences(arr, i, n - 1, j, output, key);
}



//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	int n, key;
	cin >> n >> key;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << "The first occurence of " << key << " is " << firstOccurence(arr, n, key) << endll;
	cout << "The last occurence of " << key << " is " << lastOccurence(arr, n, key) << endll;
	cout << "All occurence of " << key << " are ";
	alloccurence(arr, 0,  n, key);
	cout << endll;
	int output[n];
	memset(output, -1, sizeof(output));
	int index = storeOccurences(arr, 0, n, -1, output, key);
	for (int i = 0; i < index; ++i)
	{
		cout << output[i] << " ";
	}
	cout << index << endl;
	cout << endll;
	return 0;
}