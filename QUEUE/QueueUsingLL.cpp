/*
* @Author: Mohit Pathak
* @Date:   2021-02-24 06:15:29
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-25 04:05:35
*/

#include<iostream>
#include "queue.h"
using namespace std;

//queue
// class node {
// public:
// 	int data;
// 	node * next;
// };
// class queue {
// 	node * front;
// 	node * rear;
// public:
// 	queue() {
// 		front = rear = nullptr;
// 	}
// 	bool isempty();
// 	bool isfull();
// 	int enqueue(int data);
// 	int dequeue();
// 	int getfront();
// 	int getrear();
// 	int getlength();
// 	void create(int *arr, int n);
// 	void display();
// };

// bool queue::isempty() {
// 	return front == nullptr && rear == nullptr ? true : false;
// }
// bool queue::isfull() {
// 	node * newnode = new node;
// 	if (!newnode) {
// 		return true;
// 	} else {
// 		delete newnode;
// 		return false;
// 	}
// }
// int queue::enqueue(int data) {
// 	node * newnode = new node;
// 	if (!newnode) {
// 		return -1;
// 	}
// 	newnode->data = data;
// 	newnode->next = nullptr;
// 	if (isempty()) {
// 		front = newnode;
// 		rear = newnode;
// 	} else {
// 		rear->next = newnode;
// 		rear = newnode;
// 	}
// 	return 0;
// }

// int queue::dequeue() {
// 	int val = -1;
// 	if (!isempty()) {
// 		node *q = front;
// 		if (front == rear) {
// 			front = rear = nullptr;
// 		} else {
// 			front = front->next;
// 		}
// 		val = q->data;
// 		delete q;
// 		return val;
// 	}
// 	return val;
// }

// int queue::getfront() {
// 	if (!isempty()) {
// 		return front->data;
// 	} else {
// 		return -1;
// 	}
// }
// int queue::getrear() {
// 	if (!isempty()) {
// 		return rear->data;
// 	} else {
// 		return -1;
// 	}
// }
// int queue::getlength() {
// 	if (!isempty()) {
// 		node * counter = front;
// 		int count = 1;
// 		while (counter->next != nullptr) {
// 			counter = counter->next;
// 			count++;
// 		}
// 		return count;
// 	} else {
// 		return 0;
// 	}
// }

// void queue::create(int* arr, int n) {
// 	for (int i = 0; i < n; ++i)
// 	{
// 		enqueue(arr[i]);
// 	}
// }

// void queue::display() {
// 	cout << " <<== ";
// 	if (!isempty()) {
// 		node * p = front;
// 		while (p->next != nullptr) {
// 			cout << p->data << " -- ";
// 			p = p->next;
// 		}
// 		cout << p->data;
// 	}
// 	cout << endl;
// }
//==============================



void display(queue<int> * q) {
	int count = q->getlength();
	cout << " <== ";
	if (count != 0) {
		int i;
		for ( i = 1; i < count; ++i)
		{
			cout << q->peek(i) << " -- ";
		}
		cout << q->peek(i);
	}
	cout << endl;
}

int main() {
	queue<int> q;
	if (q.isempty()) {
		cout << "Queue is empty" << endl;
	}
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	q.create(arr, 10);
	display(&q);
	cout << q.getlength() << " " << q.getfront() << " " << q.getrear() << endl;
	cout << "==============================================" << endl;
	q.enqueue(1111);
	q.enqueue(1212);
	display(&q);
	cout << "==============================================" << endl;
	int count = q.getlength();
	for (int i = 0; i < count; ++i)
	{
		cout << q.dequeue() << " ";
	}
	if (q.isempty()) {
		cout << "Queue is empty" << endl;
	}
	display(&q);
	cout << q.getlength() << " " << q.getfront() << " " << q.getrear() << endl;
	return 0;
}