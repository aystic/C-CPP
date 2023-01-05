/*
* @Author: Mohit Pathak
* @Date:   2021-07-11 03:44:33
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-07-11 04:45:29
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

void generate_Strings(char arr[], char output[], int i, int j) {
	if (arr[i] == '\0') {
		output[j] = '\0';
		cout << output << endl;
		return;
	}
	int digit;
	digit = arr[i] - '0';
	output[j] = 'A' + digit - 1;
	generate_Strings(arr, output, i + 1, j + 1);
	if (arr[i + 1] != '\0') {
		digit = 10 * (arr[i] - '0') + (arr[i + 1] - '0');
		if (digit <= 26) {
			output[j] = 'A' + digit - 1;
			generate_Strings(arr, output, i + 2, j + 1);
		}
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
	generate_Strings(arr, output, 0, 0);
	return 0;
}