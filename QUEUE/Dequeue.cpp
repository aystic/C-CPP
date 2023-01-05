/*
* @Author: pmohit
* @Date:   2021-02-25 00:07:54
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-25 00:52:58
*/

#include<iostream>

using namespace std;

//using array

class dequeue {
	int front;
	int rear;
	int size;
	int *arr;
public:
	dequeue(int size) {
		this->size = size;
		arr = new int[size];
		front = rear = -1;
	}
	bool isempty();
	int isfull();
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
	return front == rear ? true : false;
}

int dequeue::isfull() {
	return (rear == size - 1) && (front == -1) ? 0 : ((front == -1) ? 1 : ((rear == size - 1 ? 2 : -1)));
	// returns 0 for full from front and end
	//returns 1 for full from front
	//returs 2 for full from end
	//returns -1 for not full from anywhere
}


int dequeue::insertfront(int data) {
	if (front != -1) {
		arr[front] = data;
		front--;
		return 0;
	}
	return -1;
}

int dequeue::insertrear(int data) {
	if (rear != size - 1) {
		rear++;
		arr[rear] = data;
		return 0;
	}
	return -1;
}

int dequeue::deletefront() {
	int val = -1;
	if (!isempty()) {
		front++;
		val = arr[front];
		return val;
	}
	return val;
}

int dequeue::deleterear() {
	int val = -1;
	if (!isempty()) {
		val = arr[rear];
		rear--;
		return val;
	}
	return val;
}

int dequeue::getfront() {
	if (!isempty()) {
		return arr[front + 1];
	}
	return -1;
}

int dequeue::getrear() {
	if (!isempty()) {
		return arr[rear];
	}
	return -1;
}

int dequeue::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (isfull() != 2)
			insertrear(arr[i]);
		else
			return -1;
	}
	return 0;
}

void dequeue::display() {
	cout << " <<== ";
	if (!isempty()) {
		int counter = front + 1;
		while (counter < rear) {
			cout << arr[counter] << " -- ";
			counter++;
		}
		cout << arr[counter];
	}
	cout << endl;
}

int dequeue::length() {
	if (!isempty()) {
		int count = 0;
		int p = front;
		while (p < rear) {
			p++;
			count++;
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
	dequeue dq{10};
	if (dq.isempty())
		cout << "Dequeue is empty" << endl;
	dq.create(arr, 10);
	dq.display();


	if (dq.isfull() == 0)
		cout << " Full from everywhere " << endl;
	else if (dq.isfull() == 1)
		cout << "Full from front " << endl;
	else if (dq.isfull() == 2)
		cout << "Full from rear " << endl;
	else
		cout << "Not full form anywhere " << endl;


	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << dq.deletefront() << " ";
	}
	cout << endl;
	dq.display();

	if (dq.isfull() == 0)
		cout << " Full from everywhere " << endl;
	else if (dq.isfull() == 1)
		cout << "Full from front " << endl;
	else if (dq.isfull() == 2)
		cout << "Full from rear " << endl;
	else
		cout << "Not full form anywhere " << endl;


	for (int i = 0; i < 3; ++i)
	{
		cout << dq.deleterear() << " ";
	}
	cout << endl;
	dq.display();

	if (dq.isfull() == 0)
		cout << " Full from everywhere " << endl;
	else if (dq.isfull() == 1)
		cout << "Full from front " << endl;
	else if (dq.isfull() == 2)
		cout << "Full from rear " << endl;
	else
		cout << "Not full form anywhere " << endl;

	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << dq.insertfront(i + 1) << " ";
	}
	cout << endl;
	dq.display();

	if (dq.isfull() == 0)
		cout << " Full from everywhere " << endl;
	else if (dq.isfull() == 1)
		cout << "Full from front " << endl;
	else if (dq.isfull() == 2)
		cout << "Full from rear " << endl;
	else
		cout << "Not full form anywhere " << endl;

	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	cout << "==================================" << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << dq.insertrear(i + 1) << " ";
	}
	cout << endl;
	dq.display();

	if (dq.isfull() == 0)
		cout << " Full from everywhere " << endl;
	else if (dq.isfull() == 1)
		cout << "Full from front " << endl;
	else if (dq.isfull() == 2)
		cout << "Full from rear " << endl;
	else
		cout << "Not full form anywhere " << endl;

	cout << dq.length() << " " << dq.getfront() << " " << dq.getrear() << endl;
	return 0;
}