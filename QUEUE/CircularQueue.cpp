/*
* @Author: Mohit Pathak
* @Date:   2021-02-24 04:47:55
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-24 06:15:10
*/

#include<iostream>

using namespace std;

class circularQueue {
	int front;
	int rear;
	int size;
	int* arr;
public:
	circularQueue(int size) {
		this->size = size;
		arr = new int[size];
		front = rear = 0;
	}
	bool isempty();
	bool isfull();
	int enqueue(int data);
	int dequeue();
	int getfront();
	int getrear();
	int create(int *arr, int n);
	void display();
	int length();
};

int circularQueue::length() {
	if (!isempty()) {
		int i = (front + 1) % size;
		int count = 0;
		while (i != rear) {//important
			count++;
			i = (i + 1) % size;
		}
		count++;
		return count;
	}
	return 0;
}


int circularQueue::getfront() {
	int val = -1;
	if (!isempty()) {
		return arr[(front + 1) % size];
	}
	return val;
}

int circularQueue::getrear() {
	int val = -1;
	if (!isempty()) {
		return arr[rear];
	}
	return val;
}

bool circularQueue::isempty() {
	return front == rear ? true : false;
}
bool circularQueue::isfull() {
	return (rear + 1) % size == front ? true : false;
}
int circularQueue::enqueue(int data) {
	if (!isfull()) {
		rear = (rear + 1) % size;
		arr[rear] = data;
		return 0;
	}
	return -1;
}

int circularQueue::dequeue() {
	int val = -1;
	if (!isempty()) {
		front = (front + 1) % size;
		val = arr[front];
		return val;
	}
	return val;
}

int circularQueue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (!isfull()) {
			enqueue(arr[i]);
		} else {
			return arr[i];
		}
	}
	return 0;
}

void circularQueue::display() {
	cout << " <<== ";
	if (!isempty()) {
		int i;
		for (i = (front + 1) % size; i < rear ;)
		{
			cout << arr[i] << " -- ";
			i = (i + 1) % size;
		}
		cout << arr[i];
	}
	cout << endl;
}

int main() {
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	circularQueue q{10};
	cout << q.create(arr, 10) << endl;
	q.display();
	cout << q.length() << " ";
	cout << q.getfront() << " " << q.getrear() << endl;
	if (q.enqueue(1111) == -1)
		cout << "Queue is full" << endl;
	q.display();
	for (int i = 0; i < 9; ++i)
	{
		q.dequeue();
	}
	if (q.isempty()) {
		q.display();
		cout << "Queue is empty" << endl;
	}
	cout << q.length() << " " << q.getfront() << " " << q.getrear() << endl;
	for (int i = 0; i < 5; ++i)
	{
		q.enqueue(i + 1);
	}
	q.display();
	cout << q.length() << " " << q.getfront() << " " << q.getrear() << endl;
	return 0;
}