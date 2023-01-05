/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 10:39:13
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-03 10:46:34
*/

#include<iostream>
#include<stack>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class queue {
	stack<int>s1;
	stack<int>s2;
public:
	bool empty() {
		return (s1.empty() and s2.empty());
	}

	int size() {
		return (s1.size() + s2.size());
	}

	void push(int data) {
		s1.push(data);
	}

	void pop() {
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		} else {
			s2.pop();
		}
	}

	int front() {
		int data = -1;
		if (s2.empty()) {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
		data = s2.top();
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

	queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	while (!q.empty()) {
		cout << q.front() << endll;
		q.pop();
	}
	return 0;
}