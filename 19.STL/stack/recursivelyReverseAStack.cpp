/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 17:18:08
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 19:14:28
*/

#include<iostream>
#include<stack>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void push_at_down(stack<int>&s1, int n) {
	if (s1.empty()) {
		s1.push(n);
		return;
	}
	int x = s1.top();
	s1.pop();
	push_at_down(s1, n);
	s1.push(x);
	return;
}

void recReverse(stack<int>&s1) {
	if (s1.size() == 1) {
		return;
	}
	int x = s1.top();
	s1.pop();
	recReverse(s1);
	push_at_down(s1, x);
	return;
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	stack<int> st;
	for (int i = 0; i < 6; ++i)
	{
		st.push(i * i);
	}
	recReverse(st);
	for (int i = 0; i < 6; ++i)
	{
		cout << st.top() << endll;
		st.pop();
	}
	return 0;
}