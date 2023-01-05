/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-28 08:50:18
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-28 09:06:55
*/

#include<iostream>
#include<climits>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void countingSort(int arr[], int n, int range) {
	int helper[range + 1] {};
	for (int i = 0; i < n; ++i)
	{
		helper[arr[i]]++;
	}
	int j = 0;
	for (int i = 0; i <= range; ++i)
	{
		while (helper[i]) {
			arr[j++] = i;
			helper[i]--;
		}
	}
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
	int arr[n];
	int maxElement = INT_MIN;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		maxElement = max(maxElement, arr[i]);
	}
	countingSort(arr, n, maxElement);
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endll;
	return 0;
}