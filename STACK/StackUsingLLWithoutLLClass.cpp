/*
* @Author: Mohit Pathak
* @Date:   2021-02-22 08:55:25
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 09:30:01
*/

#include<iostream>

using namespace std;

class node {
public:
	int data;
	node * next;
};
class stackll {
	node * top;
	int length;
public:
	stackll() {
		top = nullptr;
		length = 0;
	}
	void push(int data);
	int pop();
	int gettop();
	bool isfull();
	bool isempty();
	int csize() {return length;};
	void create(int *arr, int n);
	int peek(int index);
	void display();
};

void stackll::display() {
	if (!isempty()) {
		node *p = top;
		cout << " <<== ";
		while (p->next) {
			cout << p->data << " -- ";
			p = p->next;
		}
		cout << p->data << endl;
		return;
	} else {
		cout << "Stack is empty!" << endl;
		return;
	}
}

bool stackll::isempty() {
	if (!top)
		return true;
	return false;
}

bool stackll::isfull() {
	node * newnode = new node;
	if (!newnode) {
		return true;//when the heap memory is full
	} else {
		delete newnode;
		return false;
	}
}

void stackll::push(int data) {
	node * newnode = new node;
	if (!newnode) {
		cout << "Stack full" << endl;
	} else {
		newnode->data = data;
		newnode->next = top;
		top = newnode;
		length++;
	}
}

int stackll::pop() {
	int val = -1;
	if (!isempty()) {
		val = top->data;
		node *q = top;
		top = top->next;
		delete q;
		length--;
	}
	return val;
}

void stackll::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		push(arr[i]);
	}
}

int stackll::peek(int index) {
	if (index < 1 || index > length) {
		cout << "Invalid Position" << endl;
		return -1;
	} else {
		int count = index - 1;
		node *p = top;
		for (int i = 0; i < count; ++i)
		{
			p = p->next;
		}
		return p->data;
	}
}

int stackll::gettop() {
	int val = -1;
	if (!isempty()) {
		val = top->data;
	}
	return val;
}


int main() {
	stackll st;
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	st.create(arr, 10);
	st.display();
	st.push(1111);
	st.display();
	cout << st.gettop() << endl;
	cout << st.csize() << endl;
	cout << "================================" << endl;
	int count = st.csize();
	for (int i = 1; i <= count; ++i)
	{
		cout << st.peek(i) << " ";
	}
	cout << endl;
	st.peek(0);
	st.peek(count + 1);
	cout << "================================" << endl;
	cout << "popping" << endl;
	for (int i = 0; i < count; ++i)
	{
		cout << st.pop() << " ";
	}
	if (st.pop() == -1) {
		cout << "Stack empty" << endl;
	}
	cout << "================================" << endl;
	st.display();
	cout << st.gettop() << endl;

	return 0;
}