/*
* @Author: pmohit
* @Date:   2021-06-11 01:06:42
* @Last Modified by:   pmohit
* @Last Modified time: 2021-06-11 09:51:17
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------
	char arr[100][100];
	int n;
	cin >> n;
	cin.get();//TO CONSUME THE EXTRA SPACE AFTER THE N
	for (int i = 0; i < n; ++i)
	{
		cin.getline(arr[i], 100);
	}

	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}