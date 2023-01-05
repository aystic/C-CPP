/*
* @Author: Mohit Pathak
* @Date:   2021-02-22 06:54:22
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 09:14:06
*/

#include<iostream>
#include "llforStack.h"

using namespace std;


// //===========Linked List==================
// class node {
// public:
// 	int data;
// 	node * next;
// };
// class linkedlist {
// 	node * head;
// public:
// 	linkedlist() {
// 		head = nullptr;
// 	}
// 	int deletenode();
// 	void create(int* arr, int n);
// 	void insertnode(int data);
// 	int getnode(int position);
// 	void addnode(int data);
// 	node * gethead() {return head;}
// 	void sethead(node * head) { this->head = head;}
// };

// void linkedlist::addnode(int data) {
// 	node * newnode = new node;
// 	newnode->data = data;
// 	newnode->next = head;
// 	head = newnode;
// }
// void linkedlist::insertnode(int data) {
// 	node * newnode = new node;
// 	newnode->data = data;
// 	if (!head) {
// 		head = newnode;
// 		newnode->next = nullptr;
// 	} else {
// 		newnode->next = head;
// 		head = newnode;
// 	}
// }
// void linkedlist::create(int* arr, int n) {
// 	for (int i = 0; i < n; i++) {
// 		addnode(arr[i]);
// 	}
// }

// int linkedlist::deletenode() {
// 	int val = -1;
// 	if (!head) {
// 		return val;;
// 	} else {
// 		node *q = head;
// 		head = head->next;
// 		val = q->data;
// 		delete q;
// 	}
// 	return val;
// }

// int linkedlist::getnode(int position) {
// 	node *p = head;
// 	for (int i = 0; i < position - 1; ++i)
// 	{
// 		p = p->next;
// 	}
// 	return p->data;

// }
// //=========================================

//==============Stack======================

class stack {
	linkedlist l;
	int length;
public:
	stack() {
		length = 0;
	}
	bool isempty();
	void push(int data);
	int pop();
	int peek(int index);
	int csize() {return length;}
	void create(int* arr, int n);
	void display();
	int gettop();
};

bool stack::isempty() {
	if (!l.gethead())
		return true;
	return false;
}

void stack::push(int data) {
	l.addnode(data);
	length++;
}

int stack::pop() {
	int val = -1;
	if (isempty()) {
		cout << "Stack empty" << endl;
	} else {
		val = l.deletenode();
		length--;
	}
	return val;
}

int stack::peek(int index) {
	int val = -1;
	if (index < 1 || index > length) {
		cout << "Invalid Index" << endl;
	} else {
		val = l.getnode(index);
	}
	return val;
}

int stack::gettop() {
	int val = -1;
	if (!isempty()) {
		val = l.gethead()->data;
	}
	return val;
}
void stack::display() {
	if (!isempty()) {
		cout << " <<== ";
		for (int i = 1; i <= length - 1; ++i)
		{
			cout << l.getnode(i) << " -- ";
		}
		cout << l.getnode(length) << endl;

	} else {
		cout << "Stack empty!" << endl;
	}
}

void stack::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		l.addnode(arr[i]);
		length++;
	}
}

//=========================================

int main() {
	stack st;
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	st.create(arr, 10);
	st.display();
	st.push(1111);
	st.display();
	cout << st.gettop() << endl;
	cout << "================================" << endl;
	int count = st.csize();
	for (int i = 1; i < count; ++i)
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