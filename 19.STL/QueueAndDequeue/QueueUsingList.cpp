/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 09:23:52
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-03 09:29:50
*/

#include<iostream>
#include<list>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class queue {
	list<int> l;
	int cs;
public:
	queue() {
		cs = 0;
	}
	bool isempty() {
		return cs == 0;
	}
	void push(int data) {
		l.push_back(data);
		cs++;
	}
	void pop() {
		if (!isempty()) {
			l.pop_front();
			cs--;
		}
	}
	int front() {
		if (!isempty()) {
			return l.front();
		}
		return -1;
	}

	void display() {
		if (!isempty()) {
			for (auto it : l) {
				cout << "<<=" << it << " ";
			}
			cout << endll;
		}
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
	while (!q.isempty()) {
		cout << q.front() << endll;
		q.pop();
	}
	return 0;
}