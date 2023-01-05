/*
* @Author: Mohit Pathak
* @Date:   2021-07-11 03:25:40
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-11 03:43:34
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
char keypad[10][10] {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

void findAllSubstrings(char arr[], char keypad[][10], char output[], int i, int j) {
	if (arr[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}
	int index = arr[i] - '0';
	int curr = 0;
	if (index == 0 or index == 1) {
		findAllSubstrings(arr, keypad, output, i + 1, j);
	}
	while (keypad[index][curr] != '\0') {
		output[j] = keypad[index][curr];
		findAllSubstrings(arr, keypad, output, i + 1, j + 1);
		curr++;
	}
	return;
}


//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//==========================================

	char arr[100];
	cin >> arr;
	char output[100];
	findAllSubstrings(arr, keypad, output, 0, 0);
	return 0;
}