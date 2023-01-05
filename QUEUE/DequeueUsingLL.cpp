/*
* @Author: pmohit
* @Date:   2021-02-25 00:07:54
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-25 01:56:03
*/

#include<iostream>

using namespace std;

//using LinkedList

class dequeuenode {
public:
	dequeuenode* previous;
	int data;
	dequeuenode* next;
};

class dequeue {
	dequeuenode * front;
	dequeuenode * rear;
public:
	dequeue() {
		front = rear = nullptr;
	}
	bool isempty();
	bool isfull();
	int insertfront(int data);
	int insertrear(int data);
	int deletefront();
	int deleterear();
	int create(int *arr, int n);
	int length();
	int getfront();
	int getrear();
	void display();
};

bool dequeue::isempty() {
	return (front == nullptr && rear == nullptr) ? true : false;
}

bool dequeue::isfull() {
	dequeuenode * newnode = new dequeuenode;
	if (!newnode) {
		return true;
	} else {
		delete newnode;
		return false;
	}
}


int dequeue::insertfront(int data) {
	dequeuenode * newnode = new dequeuenode;
	if (!newnode)
		return -1;
	newnode->data = data;
	newnode->previous = nullptr;
	if (isempty()) {
		newnode->next = nullptr;
		front = rear = newnode;
	} else {
		newnode->next = front;
		front->previous = newnode;
		front = newnode;
	}
	return 0;
}

int dequeue::insertrear(int data) {
	dequeuenode * newnode = new dequeuenode;
	if (!newnode)
		return -1;
	newnode->data = data;
	newnode->next = nullptr;
	if (isempty()) {
		newnode->previous = nullptr;
		front = rear = newnode;
	} else {
		newnode->previous = rear;
		rear->next = newnode;
		rear = newnode;
	}
	return 0;
}

int dequeue::deletefront() {
	int val = -1;
	if (!isempty()) {
		dequeuenode *q = front;
		front = front->next;
		val = q->data;
		delete q;
		front->previous = nullptr;
		return val;
	}
	return val;
}

int dequeue::deleterear() {
	int val = -1;
	if (!isempty()) {
		dequeuenode *q = rear;
		rear = rear->previous;
		val = q->data;
		delete q;
		rear->next = nullptr;
		return val;
	}
	return val;
}

int dequeue::getfront() {
	if (!isempty()) {
		return front->data;
	}
	return -1;
}

int dequeue::getrear() {
	if (!isempty()) {
		return rear->data;
	}
	return -1;
}

int dequeue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (!isfull())
			insertrear(arr[i]);
		else
			return -1;
	}
	return 0;
}

void dequeue::display() {
	cout << " <<== ";
	if (!isempty()) {
		dequeuenode* counter = front;
		while (counter->next) {
			cout << counter->data << " -- ";
			counter = counter->next;
		}
		cout << counter->data;
	}
	cout << endl;
}

int dequeue::length() {
	if (!isempty()) {
		int count = 0;
		dequeuenode* p = front;
		while (p) {
			count++;
			p = p->next;
		}
		return count;
	}
	return 0;
}


//======================

//using linked list

//======================



int main() {
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	dequeue dq;
	if (dq.isempty())
		cout << "Dequeue is empty" << endl;
	dq.create(arr, 10);
	dq.display();
	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << dq.deletefront() << " ";
	}
	cout << endl;
	dq.display();
	for (int i = 0; i < 3; ++i)
	{
		cout << dq.deleterear() << " ";
	}
	cout << endl;
	dq.display();
	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << dq.insertfront(i + 1) << " ";
	}
	cout << endl;
	dq.display();
	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << dq.insertrear(i + 1) << " ";
	}
	cout << endl;
	dq.display();
	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	return 0;
}