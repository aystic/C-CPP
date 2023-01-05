/*
* @Author: pmohit
* @Date:   2021-02-24 00:55:04
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-24 04:36:44
*/

#include<iostream>

using namespace std;

class queue {
	int rear;
	int * arr;
	int size;
public:
	queue(int size) {
		arr = new int[size];
		this->size = size;
		rear = -1;
	}
	int enqueue(int data);
	int dequeue();
	bool isempty();
	bool isfull();
	int first();
	int last();
	int length();
	int create(int *arr, int n);
	void display();
};

int queue::length() {
	return rear + 1;
}

bool queue::isempty() {
	return rear == -1 ? true : false;
}
bool queue::isfull() {
	return length() == size ? true : false;
}
int queue::enqueue(int data) {
	if (!isfull()) {
		rear++;
		arr[rear] = data;
		return 0;
	} else {
		return -1;
	}
}

int queue::dequeue() {
	int val = -1;
	if (!isempty()) {
		val = arr[0];
		for (int i = 1; i <= rear; ++i)
		{
			arr[i - 1] = arr[i];
		}
		rear--;
	}
	return val;
}
int queue::first() {
	if (!isempty()) {
		return arr[0];
	} else {
		return -1;
	}
}
int queue::last() {
	if (!isempty()) {
		return arr[rear];
	} else {
		return -1;
	}
}
int queue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (isfull()) {
			return -1;
		}
		enqueue(arr[i]);
	}
	return 0;
}

void queue::display() {
	cout << " <<== ";
	if (!isempty()) {

		int i = 0;
		for ( i = 0; i < rear; ++i)
		{
			cout << arr[i] << " -- ";
		}
		cout << arr[i];
	}
	cout << endl;
}

int main() {
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	queue q{11};
	q.create(arr, 10);
	q.display();
	q.enqueue(1111);
	q.display();
	q.dequeue();
	q.dequeue();
	q.display();
	cout << q.length() << " " << q.first() << " " << q.last() << endl;
	while (!q.isfull()) {
		q.enqueue(9999);
	}
	if (q.isfull())
		cout << "Queue is full" << endl;
	cout << q.length() << " " << q.first() << " " << q.last() << endl;
	q.display();
	while (!q.isempty())
		q.dequeue();
	if (q.isempty())
		cout << "Queue is empty" << endl;
	cout << q.length() << " " << q.first() << " " << q.last() << endl;
	q.display();
	return 0;
}