/*
* @Author: Mohit Pathak
* @Date:   2021-02-21 05:11:40
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-21 21:52:35
*/

#include<iostream>
using namespace std;

class node {
public:
	node * previous;
	int data;
	node * next;
};
class cdll {
	node * head;
public:
	cdll() {
		head = nullptr;
	}
	void addNode(int data);
	void create(int* arr, int n);
	void display();
	void insert(int data, int position);
	void deleteNode(int position);
	int getlength();

	~cdll() {
		node *p = head;
		if (head == nullptr) {
			return;
		} else {
			node*q = p;
			p = p->next;
			while (p != head) {
				delete q;
				q = p;
				p = p->next;
			}
			delete q;
			return;
		}
	}
};

int cdll::getlength() {
	node *p = head;
	int count = 1;
	if (!head) {
		return 0;
	}
	while (p->next != head) {
		count++;
		p = p->next;
	}
	return count;
}

void cdll::addNode(int data) {
	node * newnode = new node;
	newnode->data = data;
	if (!head) {
		head = newnode;
		newnode->next = newnode;
		newnode->previous = newnode;
	} else {
		node *p = head;
		while (p->next != head) {
			p = p->next;
		}
		newnode->next = head;
		newnode->previous = p;
		p->next = newnode;
		head->previous = newnode;
	}
}
void cdll::create(int* arr, int n) {
	int i = 0;
	while (n--) {
		addNode(arr[i]);
		i++;
	}
}

void cdll::display() {
	node *p = head;
	if (!p) {
		cout << "Empty List" << endl;
		return;
	}
	while (p->next != head) {
		cout << p->data << " --> ";
		p = p->next;
	}
	cout << p->data << endl;
	return;
}

void cdll::insert(int data, int position) {
	if (position < 1 || position > getlength() + 1) {
		cout << "Invalid position" << endl;
		return;
	} else {
		node * newnode = new node;
		newnode->data = data;
		if (position == 1) {
			newnode->previous = head->previous;
			newnode->next = head;
			head->previous->next = newnode;
			head->previous = newnode;
			head = newnode;
			return;
		} else {
			node *p = head;
			for (int i = 0; i < position - 2; ++i)
			{
				p = p->next;
			}
			newnode->previous = p;
			newnode->next = p->next;
			p->next->previous = newnode;
			p->next = newnode;
			return;
		}
	}
}

void cdll::deleteNode(int position) {
	int length = getlength();
	if (position < 1 || position > length) {
		cout << "Invalid Position" << endl;
		return;
	} else {
		if (position == 1) {
			if (length == 1) {
				delete head;
				head = nullptr;
				return;
			}
			head->previous->next = head->next;
			head->next->previous = head->previous;
			node *p = head;
			head = head->next;
			delete p;
		} else {
			if (position == length) {
				node *p = head->previous;
				p->previous->next = head;
				head->previous = p->previous;
				delete p;
			} else {
				node *p = head;
				for (int i = 0; i < position - 1; ++i)
				{
					p = p->next;
				}
				p->previous->next = p->next;
				p->next->previous = p->previous;
				delete p;
			}
		}
	}
}


int main() {
	int arr[] {11};
	cdll c;
	c.create(arr, 1);
	// c.display();
	// cout << c.getlength() << endl;
	// c.insert(0, 0);
	// c.insert(0, 11);
	// c.insert(0, 1);
	// c.display();
	// c.insert(1010, 11);
	// c.display();
	// c.insert(25, 5);
	// c.display();
	// cout << c.getlength() << endl;
	// c.deleteNode(0);
	// c.deleteNode(13);
	// c.deleteNode(1);
	// c.display();
	// c.deleteNode(11);
	// c.display();
	// c.deleteNode(5);
	// c.display();
	cout << c.getlength() << endl;
	c.deleteNode(1);
	cout << c.getlength() << endl;
	c.display();
	return 0;
}