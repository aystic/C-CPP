/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 10:28:55
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-03 10:37:13
*/

#include<iostream>
#include<queue>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class stack {
	queue<int> q1;
	queue<int>q2;
public:
	bool empty() {
		return (q1.empty() and q2.empty());
	}

	int size() {
		return q1.size() + q2.size();
	}

	void push(int data) {
		if (!q1.empty()) {
			q1.push(data);
		} else {
			q2.push(data);
		}
	}
	void pop() {
		if (!q1.empty()) {
			for (int i = 0; i < size() - 1; ++i)
			{
				q2.push(q1.front());
				q1.pop();
			}
			q1.pop();
		} else {
			for (int i = 0; i < size() - 1; ++i)
			{
				q1.push(q2.front());
				q2.pop();
			}
			q2.pop();
		}
	}

	int top() {
		int data = -1;
		if (!q1.empty()) {
			for (int i = 0; i < size() - 1; ++i)
			{
				q2.push(q1.front());
				q1.pop();
			}
			data = q1.front();
			q2.push(q1.front());
			q1.pop();

		} else {
			for (int i = 0; i < size() - 1; ++i)
			{
				q1.push(q2.front());
				q2.pop();
			}
			data = q2.front();
			q1.push(q2.front());
			q2.pop();
		}
		return data;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	cout << st.top() << endll;
	while (!st.empty()) {
		cout << st.top() << endll;
		st.pop();
	}
	return 0;
}