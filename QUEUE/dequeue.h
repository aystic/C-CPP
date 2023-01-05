/*
* @Author: Mohit Pathak
* @Date:   2021-02-25 04:08:31
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-25 04:29:17
*/

template <class T>
class dequeuenode {
public:
	dequeuenode<T>* previous;
	T data;
	dequeuenode<T>* next;
};

template <class T>
class dequeue {
	dequeuenode<T> * front;
	dequeuenode<T> * rear;
public:
	dequeue<T>() {
		front = rear = nullptr;
	}
	bool isempty();
	bool isfull();
	int insertfront(T data);
	int insertrear(T data);
	T deletefront();
	T deleterear();
	int create(T *arr, int n);
	int length();
	T getfront();
	T getrear();
	T peek(int index);
};

template <class T>
bool dequeue<T>::isempty() {
	return (front == nullptr && rear == nullptr) ? true : false;
}

template <class T>
bool dequeue<T>::isfull() {
	dequeuenode<T> * newnode = new dequeuenode<T>;
	if (!newnode) {
		return true;
	} else {
		delete newnode;
		return false;
	}
}


template <class T>
int dequeue<T>::insertfront(T data) {
	dequeuenode<T> * newnode = new dequeuenode<T>;
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

template <class T>
int dequeue<T>::insertrear(T data) {
	dequeuenode<T> * newnode = new dequeuenode<T>;
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

template <class T>
T dequeue<T>::deletefront() {
	T val = -1;
	if (!isempty()) {
		dequeuenode<T> *q = front;
		front = front->next;
		val = q->data;
		delete q;
		front->previous = nullptr;
		return val;
	}
	return val;
}

template <class T>
T dequeue<T>::deleterear() {
	T val = -1;
	if (!isempty()) {
		dequeuenode<T> *q = rear;
		rear = rear->previous;
		val = q->data;
		delete q;
		rear->next = nullptr;
		return val;
	}
	return val;
}

template <class T>
T dequeue<T>::getfront() {
	if (!isempty()) {
		return front->data;
	}
	return -1;
}

template <class T>
T dequeue<T>::getrear() {
	if (!isempty()) {
		return rear->data;
	}
	return -1;
}

template <class T>
int dequeue<T>::create(T *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		if (!isfull())
			insertrear(arr[i]);
		else
			return -1;
	}
	return 0;
}

template <class T>
T dequeue<T>::peek(int index) {
	T val = -1;
	if (!isempty()) {
		dequeuenode<T> * p = front;
		for (int i = 0; i < index - 1; ++i)
		{
			p = p->next;
		}
		val = p->data;
	}
	return val;
}

template <class T>
int dequeue<T>::length() {
	if (!isempty()) {
		int count = 0;
		dequeuenode<T>* p = front;
		while (p) {
			count++;
			p = p->next;
		}
		return count;
	}
	return 0;
}