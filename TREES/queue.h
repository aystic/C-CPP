/*
* @Author: Mohit Pathak
* @Date:   2021-02-24 09:24:30
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-27 06:23:27
*/

template <class T>
class queuenode {
public:
	T data;
	queuenode<T> * next;
};


template <class T>
class queue {
	queuenode<T> * front;
	queuenode<T> * rear;
public:
	queue() {
		front = rear = nullptr;
	}
	bool isempty();
	bool isfull();
	int enqueue(T data);
	T dequeue();
	T getfront();
	T getrear();
	int getlength();
	void create(T *arr, int n);
	T peek(int index);
};

template <class T>
bool queue<T>::isempty() {
	return front == nullptr && rear == nullptr ? true : false;
}

template <class T>
bool queue<T>::isfull() {
	queuenode<T> * newnode = new queuenode<T>;
	if (!newnode) {
		return true;
	} else {
		delete newnode;
		return false;
	}
}

template <class T>
int queue<T>::enqueue(T data) {
	queuenode<T> * newnode = new queuenode<T>;
	if (!newnode) {
		return -1;
	}
	newnode->data = data;
	newnode->next = nullptr;
	if (isempty()) {
		front = newnode;
		rear = newnode;
	} else {
		rear->next = newnode;
		rear = newnode;
	}
	return 0;
}

template <class T>
T queue<T>::dequeue() {
	T val = nullptr;
	if (!isempty()) {
		queuenode<T> *q = front;
		if (front == rear) {
			front = rear = nullptr;
		} else {
			front = front->next;
		}
		val = q->data;
		delete q;
		return val;
	}
	return val;
}

template <class T>
T queue<T>::getfront() {
	if (!isempty()) {
		return front->data;
	} else {
		return -1;
	}
}
template <class T>
T queue<T>::getrear() {
	if (!isempty()) {
		return rear->data;
	} else {
		return -1;
	}
}
template <class T>
int queue<T>::getlength() {
	if (!isempty()) {
		queuenode<T> * counter = front;
		int count = 1;
		while (counter->next != nullptr) {
			counter = counter->next;
			count++;
		}
		return count;
	} else {
		return 0;
	}
}

template <class T>
void queue<T>::create(T* arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		enqueue(arr[i]);
	}
}

template <class T>
T queue<T>::peek(int index) {
	T val = -1;
	if (!isempty()) {
		queuenode<T> *p = front;
		for (int i = 0; i < index - 1; ++i)
		{
			if (p == rear)
				return val;
			p = p->next;
		}
		val = p->data;
	}
	return val;
}
