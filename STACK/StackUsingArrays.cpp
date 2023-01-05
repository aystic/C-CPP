/*
* @Author: pmohit
* @Date:   2021-02-22 02:42:01
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 03:47:11
*/

#include<iostream>

using namespace std;

class stack {
	int size;
	int top;
	int* arr;
public:

	//constructor function
	stack(int size) {
		arr = new int[size];
		this->size = size;
		top = -1;
	}
	bool isempty();
	bool isfull();
	void create(int* arr, int n);
	void push(int data);
	int pop();
	void display();
	int gettop();
	int peek(int index);
	int csize();
};

int stack::csize() {
	return top + 1;
}

int stack::gettop() {
	return arr[top];
}

//fuction to check if stack is full
bool stack::isfull() {
	if (top == size - 1) {
		return true;
	}
	return false;
}

//function to check if stack is empty
bool stack::isempty() {
	if (top == -1)
		return true;
	return false;
}

//function to add an element O(1)
void stack::push(int data) {
	if (!isfull()) {
		top++;
		arr[top] = data;
		display();
	} else {
		cout << "Stack is full" << endl;
		return;
	}
}

//function to delete an element O(1)
int stack::pop() {
	if (!isempty()) {
		int x = arr[top];
		top--;
		display();
		return x;
	} else {
		cout << "Stack is empty" << endl;
		return -1;
	}
}
void stack::create(int*arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		push(arr[i]);
	}
}



//function to display the stack O(n)
void stack::display() {
	if (!isempty()) {
		int counter = 0;
		while (counter < top) {
			cout << arr[counter] << " - ";
			counter++;
		}
		cout << arr[counter] << " ==>>" << endl;
		return;
	} else {
		cout << "Stack is empty!" << endl;
		return;
	}
}

//function to peek an element O(1)
int stack::peek(int index) {
	if (index > csize() || index < 1) {
		cout << "Invalid index" << endl;
		return -1;
	} else {
		return arr[csize() - index];
	}
}





int main() {
	stack st{11};
	int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 0};
	st.create(arr, 10);
	st.display();
	// st.push(1010);
	// st.pop();

	cout << "========================" << endl;
	// cout << st.gettop() << endl;
	int count = st.csize();
	for (int i = 1; i <= count; ++i)
	{
		cout << st.peek(i) << endl;
	}
	st.peek(0);
	st.peek(11);
}