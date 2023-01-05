/*
* @Author: Mohit Pathak
* @Date:   2021-06-11 11:17:43
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-11 15:27:31
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<climits>

using namespace std;
#define endll '\n'
//--------------------------------------

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------
	int maxlength = INT_MIN;
	char arr1[100];
	char arr2[100];
	int n;
	cin >> n;
	cin.get();//REQUIRED TO CONSUME THE \N CONTAINED IN THE INPUT BUFFER
	for (int i = 0; i < n; ++i)
	{
		int count = 0;
		char ch = cin.get();
		while (ch != '\n') {
			arr1[count++] = ch;
			ch = cin.get();
		}
		arr1[count] = '\0';
		if (count > maxlength) {
			maxlength = count;
			for (int i = 0; i < count; ++i)
			{
				arr2[i] = arr1[i];
			}
			arr2[count] = '\0';
		}
	}
	cout << arr2 << endll;
	return 0;
}