/*
* @Author: Mohit Pathak
* @Date:   2021-02-19 21:50:18
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-19 23:02:47
*/

#include<iostream>
using namespace std;

class node {
public:
	int data;
	node * next;
};

class clinkedlist {
	node* head;
public:
	clinkedlist() {
		head = nullptr;
	}
	node * gethead() {return head;}
	void sethead(node *p) { head = p;}
	void addNode(int data) {
		node * newnode = new node;
		newnode->data = data;
		if (!head) {
			head = newnode;
			newnode->next = newnode;
			return;
		}
		node * counter = head;
		while (counter->next != head) {
			counter = counter->next;
		}
		counter->next = newnode;
		newnode->next = head;
		return;
	}
	void create(int* arr, int length) {
		for (int i = 0; i < length; ++i)
		{
			addNode(arr[i]);
		}
	}
	void display() {
		if (!head) {
			cout << "list empty!" << endl;
			return;
		}
		node *p = head;
		while (p->next != head) {
			cout << p->data << " --> ";
			p = p->next;
		}
		cout << p->data << endl;
		return;
	}
	void rDisplay(node *p) {
		if (p->next == head) {
			cout << p->data << endl;
			return;
		}
		cout << p->data << " --> ";
		rDisplay(p->next);
		return;
	}
	int getLength() {
		if (!head) {
			return 0;
		}
		int count = 1;
		node *p = head;
		while (p->next != head) {
			count++;
			p = p->next;
		}
		return count;
	}
	void insert(int data, int position) {
		if (position < 1 || position > (getLength() + 1)) {
			cout << "Invalid Position!" << endl;
			return;
		}
		if (position == (getLength() + 1)) {
			addNode(data);
			return;
		} else if (position == 1) {
			node * newnode = new node;
			newnode->data = data;
			node * last = head;
			int length = getLength() - 1;
			while (length--) {
				last = last->next;
			}
			last->next = newnode;
			newnode->next = head;
			head = newnode;
			return;
		} else {
			node * newnode = new node;
			newnode->data = data;
			node *p = head;
			int count = 1;
			while (1) {
				if (count == position - 1)
					break;
				count++;
				p = p->next;
			}
			newnode->next = p->next;
			p->next = newnode;
			return;
		}

	}
	void deleteNode(int position) {
		int length = getLength();
		if (position < 1 || position > length) {
			cout << "Invalid Position" << endl;
			return;
		}
		if (position == 1) {
			node *p = head;
			head = head->next;
			int count = length - 1;
			while (count--)
				p = p->next;
			node *q = p->next;
			p->next = head;
			delete q;
			return;
		} else {
			int count = position - 2;
			node *p = head;
			for (int i = 0; i < count; i++) {
				p = p->next;
			}
			node *q = p->next;
			p->next = p->next->next;
			delete q;
			return;

		}
	}

	void displayCircular() {
		int length = 3 * getLength();
		node *p = head;
		while (length--) {
			cout << p->data << " --> ";
			p = p->next;
		}
	}
};



int main() {
	int a[] {1, 3, 4, 5, 6, 7, 8, 21};
	clinkedlist c;
	c.create(a, 8);
	c.display();
	c.rDisplay(c.gethead());
	cout << "==============================" << endl;
	c.insert(100, 1);
	c.display();
	c.insert(1000, 10);
	c.display();
	c.insert(99, 5);
	c.insert(55, 0);
	c.insert(999, 20);
	c.display();
	cout << "===================================" << endl;
	c.deleteNode(0);
	c.deleteNode(12);
	c.deleteNode(1);
	c.display();
	c.deleteNode(10);
	c.display();
	c.deleteNode(5);
	c.display();
	// c.displayCircular();
	return 0;
}