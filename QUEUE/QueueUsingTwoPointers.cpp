/*
* @Author: Mohit Pathak
* @Date:   2021-02-24 01:30:13
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-24 04:38:43
*/

#include<iostream>

using namespace std;

class queue {
	int front;
	int rear;
	int *arr;
	int size;
public:
	queue(int size) {
		this->size = size;
		front = rear = -1;
		arr = new int[size];
	}
	int enqueue(int data);
	int dequeue();
	int getfront();
	int getrear();
	bool isfull();
	bool isempty();
	void display();
	int create(int *arr, int n);
	int length();
};

int queue::length() {
	int i = front + 1;
	int count = 0;
	while (i <= rear) {
		count++;
		i++;
	}
	return count;
}

bool queue::isfull() {
	return rear == size - 1 ? true : false;
}
bool queue::isempty() {
	return front == rear ? true : false;
}
int queue::getfront() {
	return !isempty() ? arr[front + 1] : -1;
}
int queue::getrear() {
	return !isempty() ? arr[rear] : -1;
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
		front++;
		val = arr[front];
		return val;
	} else {
		front = rear = -1; //Resetting of the pointers
	}
	return val;
}

void queue::display() {
	cout << " <<== ";
	if (!isempty()) {
		int i = front + 1;
		while (i < rear) {
			cout << arr[i] << " -- ";
			i++;
		}
		cout << arr[i];
	}
	cout << endl;
}
int queue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (!isfull()) {
			enqueue(arr[i]);
		} else {
			return -1;
		}
	}
	return 0;
}



int main() {
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 1010};
	queue q{11};
	q.create(arr, 10);
	q.display();
	q.enqueue(1111);
	if (q.enqueue(1212) == -1)
		cout << "queue full" << endl;
	q.display();
	cout << q.length() << " " << q.getfront() << " " << q.getrear() << endl;
	while (!q.isempty()) {
		q.dequeue();
	}
	if (q.isempty())
		q.display();
	cout << q.length() << " " << q.getfront() << " " << q.getrear() << endl;
	if (q.isfull()) {
		cout << "queue is full" << endl;
	}
	if (q.isempty()) {
		cout << "queue is empty" << endl;
	}

	return 0;
}