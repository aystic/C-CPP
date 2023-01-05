/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 17:12:07
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 17:17:52
*/

#include<iostream>
#include<stack>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void transfer(stack<int>&s1, stack<int>&s2, int n) {
	for (int i = 0; i < n; ++i)
	{
		s2.push(s1.top());
		s1.pop();
	}
}


void reverse(stack<int>&s1) {
	stack<int>s2;
	int n = s1.size();
	int x;
	for (int i = 0; i < n; ++i)
	{
		//storing the top element
		x = s1.top();
		//popping all the reqd n-i elements
		transfer(s1, s2, n - i);
		s1.push(x);
		//pushing the remaining n-i-1 elements back into the original stack
		transfer(s2, s1, n - i - 1);
	}
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

	reverse(st);
	for (int i = 0; i < 6; ++i)
	{
		cout << st.top() << endll;
		st.pop();
	}
	return 0;
}