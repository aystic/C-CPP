/*
* @Author: Mohit Pathak
* @Date:   2021-06-11 10:37:18
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-11 10:51:46
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>

using namespace std;
#define endll '\n'
//--------------------------------------

void removeDuplicatesM1(char arr[]) {
	char current = arr[0];
	int i = 1;
	while (current != '\0') {
		if (arr[i] == current) {
			arr[i] = '*';
		} else {
			current = arr[i];
		}
		i++;
	}
	for (int i = 0; i < strlen(arr) - 1; ++i)
	{
		if (arr[i] != '*') {
			cout << arr[i];
		}
	}
	cout << endll;

}

void removeDuplicatesM2(char arr[]) {
	int j = 0, i = 1;
	while (arr[i] != '\0') {
		if (arr[i] == arr[j]) {
			i++;
		} else {
			j++;
			arr[j] = arr[i];
		}
	}
	arr[++j] = '\0';
	cout << arr << endl;

}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char arr[100];
	cin >> arr;
	removeDuplicatesM2(arr);
	return 0;
}