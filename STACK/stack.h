/*
* @Author: Mohit Pathak
* @Date:   2021-02-22 09:51:46
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 09:57:55
*/
template <class T>
class node {
public:
	T data;
	node * next;
};

template <class T>
class stack {
	node<T> * top;
	int length;
public:
	stack() {
		top = nullptr;
		length = 0;
	}
	int push(T data);
	T pop();
	T gettop();
	bool isfull();
	bool isempty();
	int csize() {return length;};
	void create(T *arr, int n);
	T peek(int index);
};

template <class T>
bool stack<T>::isempty() {
	if (!top)
		return true;
	return false;
}

template <class T>
bool stack<T>::isfull() {
	node<T> * newnode = new node<T>;
	if (!newnode) {
		return true;//when the heap memory is full
	} else {
		delete newnode;
		return false;
	}
}

template <class T>
int stack<T>::push(T data) {
	node<T> * newnode = new node<T>;
	if (!newnode) {
		return -1;
	} else {
		newnode->data = data;
		newnode->next = top;
		top = newnode;
		length++;
		return 0;
	}
}

template <class T>
T stack<T>::pop() {
	T val = -1;
	if (!isempty()) {
		val = top->data;
		node<T> *q = top;
		top = top->next;
		delete q;
		length--;
	}
	return val;
}

template <class T>
void stack<T>::create(T *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		push(arr[i]);
	}
}

template <class T>
T stack<T>::peek(int index) {
	if (index < 1 || index > length) {
		return -1;
	} else {
		int count = index - 1;
		node<T> *p = top;
		for (int i = 0; i < count; ++i)
		{
			p = p->next;
		}
		return p->data;
	}
}

template <class T>
T stack<T>::gettop() {
	T val = -1;
	if (!isempty()) {
		val = top->data;
	}
	return val;
}
