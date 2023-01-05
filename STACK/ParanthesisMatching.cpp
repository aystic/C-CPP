/*
* @Author: Mohit Pathak
* @Date:   2021-02-22 23:27:19
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-23 01:59:07
*/

#include<iostream>
#include "stack.h"
using namespace std;

int main() {
	string s;
	cin >> s;
	stack<char> st;
	for (int i = 0; s[i] < '\0'; ++i)
	{
		if (s[i] == '(' || s[i] == '{' || s[i] == '[' )
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == '}' || s[i] == ']' ) {
			if (st.isempty()) {
				cout << "Not matching " << endl;
				return 0;
			} else {
				if (s[i] == ')') {
					if (st.pop() != '(') {
						cout << "Not matching" << endl;
						return 0;
					}
				}
				if (s[i] == '}') {
					if (st.pop() != '{') {
						cout << "Not matching" << endl;
						return 0;
					}
				}
				if (s[i] == ']') {
					if (st.pop() != '[') {
						cout << "Not matching" << endl;
						return 0;
					}
				}
			}
		}
	}
	if (st.isempty()) {
		cout << "mathcing" << endl;
	}

	return 0;
}