/*
* @Author: Mohit Pathak
* @Date:   2021-02-26 03:58:52
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-26 04:22:30
*/

#include<iostream>
#include "stack.h"
using namespace std;

class queue {
	stack<int>* s1;
	stack<int>* s2;
public:
	queue() {
		s1 = new stack<int>;
		s2 = new stack<int>;
	}
	void enqueue(int data);
	int dequeue();
	void create(int *arr, int n);
	void display();
};
void queue::enqueue(int data) {
	s1->push(data);
}
int queue::dequeue() {
	int val = -1;
	if (s2->isempty()) {
		while (!s1->isempty()) {
			s2->push(s1->pop());
		}
	}
	val = s2->pop();
	return val;
}
void queue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		enqueue(arr[i]);
	}
}
void queue::display() {
	cout << " <<== ";
	if (!s2->isempty()) {
		int i;
		for ( i = 1; i < s2->getlength() - 1; ++i)
		{
			cout << s2->peek(i) << " -- ";
		}
		if (s1->isempty())
			cout << s2->peek(i);
		else {
			cout << s2->peek(i) << " -- ";
		}
	}
	if (!s1->isempty()) {
		int i;
		for ( i = s1->getlength() ; i > 1 ; --i)
		{
			cout << s1->peek(i) << " -- ";
		}
		cout << s1->peek(i);
	}
	cout << endl;
}

int main() {
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	queue q;
	q.create(arr, 10);
	q.display();
	q.enqueue(1111);
	q.display();
	cout << q.dequeue() << endl;
	q.display();
	for (int i = 0; i < 5; ++i)
	{
		cout << q.dequeue() << " ";
	}
	cout << endl;
	q.display();
	for (int i = 0; i < 3; ++i)
	{
		q.enqueue(i + 1);
	}
	q.display();
	return 0;
}