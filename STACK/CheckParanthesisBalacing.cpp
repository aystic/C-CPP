/*
* @Author: Mohit Pathak
* @Date:   2021-02-22 09:35:35
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 10:06:32
*/

#include<iostream>
#include "stack.h"

using namespace std;
int main() {
	string s;
	stack<char> st;
	cin >> s;
	for (int i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '(') {
			st.push('(');
		}
		if (s[i] == ')') {
			if (st.pop() == -1) {
				cout << "Not balanced!" << endl;
				return 0;
			}
		}
	}
	if (st.isempty()) {
		cout << "balanced" << endl;
	}
	return 0;
}