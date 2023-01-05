/*
* @Author: Mohit Pathak
* @Date:   2021-06-12 23:46:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-12 23:58:31
*/

//#include<bits/stdc++.h>
#include<iostream>
// #include<string>
#include<cstring>
using namespace std;
#define endll '\n'
//--------------------------------------
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char s[100] {"this, is, test string for testing the string, tokenizer"};
	char *ch = strtok(s, " ");//STORES AS ch--->|this|\0|
	cout << ch << endl;
	while (ch) {//WHEN THE STRING IS EXHAUSTED IT RETURNS NULL
		ch = strtok(NULL, " ");
		cout << ch << endl;
	}
	return 0;
}
