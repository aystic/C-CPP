/*
* @Author: Mohit Pathak
* @Date:   2021-06-08 18:41:59
* @Last Modified by:   pmohit
* @Last Modified time: 2021-06-08 18:47:07
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void generate_all_substrings(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			for (int k = i; k <= j; k++) {
				cout << arr[k] << " ";
			}
			cout << endll;
		}
	}
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int arr[5] = {1, 2, 3, 4, 5};
	generate_all_substrings(arr, 5);


	return 0;
}