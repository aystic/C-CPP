/*
* @Author: Mohit Pathak
* @Date:   2021-02-23 10:00:04
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-23 10:49:45
*/

#include<iostream>
#include "stack.h"
using namespace std;

int precedence(char a) {
	int val = 0;
	val = (a == '^') ? 4 : ((a == '*' || a == '/' ? 3 : ((a == '+' || a == '-' ? 2 : ((a == '(' || a == ')') ? 1 : 0) ))));
	return val;
}

int main() {
	cout << "===========Finding the Postfix expression=============" << endl;
	string s;
	cin >> s;
	stack<char> st;
	int i = 0;
	while (s[i] != '\0') {
		int cp = precedence(s[i]);
		if (cp == 0) {
			cout << s[i];
		} else {
			if (s[i] == '(')
				st.push(s[i]);
			else {
				while (!st.isempty() && precedence(st.gettop()) >= cp) {
					if (st.gettop() == '(') {
						st.pop();
						break;
					}
					cout << st.pop();
				}
				if (cp != 1)
					st.push(s[i]);
			}
		}
		i++;
	}
	while (!st.isempty()) {
		cout << st.pop();
	}
	cout << endl;

	return 0;
}