/*
* @Author: Mohit Pathak
* @Date:   2021-02-23 10:50:28
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-23 11:13:52
*/

#include<iostream>
#include "stack.h"
#include<cmath>
using namespace std;

bool isoperator(char a) {
	return (a == '*' || a == '/' || a == '+' || a == '-' || a == '^') ? true : false;
}


int main() {
	string s;
	cin >> s;
	stack<int> st;
	int i = 0;
	while (s[i] != '\0') {
		if (!isoperator(s[i])) {
			st.push((int)s[i] - 48);
		} else {
			if (s[i] == '^') {
				int sec = st.pop();
				st.push(pow(st.pop(), sec));
			}
			if (s[i] == '/') {
				int sec = st.pop();
				st.push(st.pop() / sec);
			}
			if (s[i] == '*') {
				int sec = st.pop();
				st.push(st.pop()*sec);
			}
			if (s[i] == '+') {
				int sec = st.pop();
				st.push(st.pop() + sec);
			}
			if (s[i] == '-') {
				int sec = st.pop();
				st.push(st.pop() - sec);
			}
		}
		i++;
	}
	cout << st.pop() << endl;

	return 0;
}