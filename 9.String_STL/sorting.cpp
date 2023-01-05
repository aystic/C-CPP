/*
* @Author: Mohit Pathak
* @Date:   2021-06-12 23:38:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-12 23:46:04
*/

//#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
#define endll '\n'
//--------------------------------------

bool compare(string a, string b) {
	if (a.length() == b.length())
		return a < b;
	return a.length() > b.length();
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	int n;
	cin >> n;
	cin.get();//TO CONSUME THE \N OF THE INPUT BUFFER
	string s[n];
	for (int i = 0; i < n; ++i)
	{
		getline(cin, s[i]);
	}
	cout << "sorting lexicograhically" << endl;
	sort(s, s + n);//LEXICOGRAPHICALLY SORTING
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}
	cout << "sorting on the basis of length of the string" << endl;
	sort(s, s + n, compare);
	for (int i = 0; i < n; ++i)
	{
		cout << s[i] << endl;
	}

	return 0;
}