/*
* @Author: Mohit Pathak
* @Date:   2021-07-09 11:37:47
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-10 05:28:57
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

void replacewithPI(char arr[], int s) {
	//BASE CASE
	if (arr[s] == '\0' or arr[s + 1] == '\0')return;
	if (arr[s] == 'p' and arr[s + 1] == 'i') {
		//DO THE SHIFTING AND REPLACEMENT
		int j = strlen(arr);
		while (j >= s + 2) {
			arr[j + 2] = arr[j];
			j--;
		}
		arr[s++] = '3';
		arr[s++] = '.';
		arr[s++] = '1';
		arr[s++] = '4';
		replacewithPI(arr, s);
	} else {
		replacewithPI(arr, s + 1);
	}

}




//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	char arr[1000];
	cin >> arr;
	replacewithPI(arr, 0);
	cout << arr << endl;
	return 0;
}