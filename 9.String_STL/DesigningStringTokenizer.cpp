/*
* @Author: Mohit Pathak
* @Date:   2021-06-13 02:10:15
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-16 21:57:12
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;
#define endll '\n'
//--------------------------------------

char* tokenizer(char* arr, char delim) {
	static char* source = nullptr;
	if (arr) { //IF THE PASSES VALUE IS NOT NULL
		source = new char[strlen(arr) + 1];
		strcpy(source, arr);
		source[strlen(arr) + 1] = '\0';
	}

	if (!source) { //if the string is exhausted then return null
		return NULL;
	}

	char *output = new char[sizeof(source) / sizeof(char)];
	int i = 0;
	for (i = 0; source[i] != delim; ++i)
	{
		output[i] = source[i];
		if (source[i] == '\0') {
			output[i] = '\0';
			source = NULL;
			return output;
		}
	}
	output[i] = '\0';
	source = &source[i + 1];
	return output;
}




int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char arr[100] {"this, is, test string for, the custom string, tokenizer"};
	cout << arr << endl;
	char *ch = tokenizer(arr, ',');
	cout << ch << endl;
	cout << "Now getting the whole string" << endl;
	ch = tokenizer(arr, ',');
	cout << ch << endl;
	while (ch) {
		ch = tokenizer(nullptr, ',');
		cout << ch << endl;
	}
	return 0;
}