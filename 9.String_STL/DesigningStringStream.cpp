/*
* @Author: Mohit Pathak
* @Date:   2021-06-13 02:41:31
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-13 02:52:49
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
#define endll '\n'
//--------------------------------------

int convert(string s) {
	int power = s.length() - 1;
	int count = s.length();
	int i = 0;
	int number = 0;
	while (count--) {
		switch (s[i]) {
		case '0':
			number += pow(10, power) * 0;
			break;
		case '1':
			number += pow(10, power) * 1;
			break;
		case '2':
			number += pow(10, power) * 2;
			break;
		case '3':
			number += pow(10, power) * 3;
			break;
		case '4':
			number += pow(10, power) * 4;
			break;
		case '5':
			number += pow(10, power) * 5;
			break;
		case '6':
			number += pow(10, power) * 6;
			break;
		case '7':
			number += pow(10, power) * 7;
			break;
		case '8':
			number += pow(10, power) * 8;
			break;
		case '9':
			number += pow(10, power) * 9;
			break;
		}
		power--;
		i++;
	}
	return number;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	string s{"12345"};
	int x = convert(s);
	cout << x + 10 << endl;
	return 0;
}