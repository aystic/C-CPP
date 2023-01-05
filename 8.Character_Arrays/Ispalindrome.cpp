/*
* @Author: Mohit Pathak
* @Date:   2021-06-11 10:27:44
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-11 10:35:56
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;
#define endll '\n'
//--------------------------------------

bool isPalindrome(char arr[]) {
	int i = 0, j = strlen(arr) - 1;
	while (i < j) {
		if (arr[i] == arr[j] or arr[i] - arr[j] == 32 or arr[i] - arr[j] == -32) {
			i++;
			j--;
		} else {
			return false;
		}
	}
	return true;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char arr[100];
	cin >> arr;
	if (isPalindrome(arr)) {
		cout << "String is palindrome" << endl;
	} else {
		cout << "String is not a palindrome" << endl;
	}

	return 0;
}