/*
* @Author: Mohit Pathak
* @Date:   2021-06-12 02:28:06
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-12 02:32:09
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	string st{"Hello this string is for testing iteration"};

	for (int i = 0; i < st.length(); ++i)
	{
		cout << st[i];
	}
	cout << endl;


	for (auto it = st.begin(); it != st.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	for (string::iterator it = st.begin(); it != st.end(); ++it)
	{
		cout << *it;
	}
	cout << endl;

	for (auto c : st)
		cout << c;
	cout << endl;

	for (auto c : st)
		cout << c;
	cout << endl;

	return 0;
}