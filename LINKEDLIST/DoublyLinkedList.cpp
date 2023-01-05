/*
* @Author: pmohit
* @Date:   2021-02-20 00:41:39
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-20 08:38:39
*/

#include<iostream>

using namespace std;




//==============Doubly linked list and its related classes==========

class node {
public:
	node * previous;
	int data;
	node * next;
};
class DoublyLinkedList {
	node * head;
	node * last;
public:
	DoublyLinkedList() {
		head = nullptr;
		last = head;
	}
	void addNode(int data);
	void create(int* arr, int n);
	void display();
	int getLength();
	void insert(int data, int position);
	void deleteNode(int position);
	void reverseDisplay();
	void reverseTheList();

};

void DoublyLinkedList::addNode(int data) {
	node * newnode = new node;
	newnode->data = data;
	if (!head) {
		newnode->previous = nullptr;
		head = newnode;
		last = newnode;
		newnode->next = nullptr;
		return;
	} else {
		last->next = newnode;
		newnode->previous = last;
		newnode->next = nullptr;
		last = newnode;
		return;
	}
}

void DoublyLinkedList::create(int* arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		addNode(arr[i]);
	}
}

void DoublyLinkedList::display() {
	if (!head) {
		cout << "List empty!" << endl;
		return;
	} else {
		node *p = head;
		while (p->next) {
			cout << p->data << " --> ";
			p = p->next;
		}
		cout << p->data << endl;
		return;
	}
}

int DoublyLinkedList::getLength() {
	node *p = head;
	if (!head)
		return 0;
	int count = 1;
	while (p != last) {
		count++;
		p = p->next;
	}
	return count;
}

void DoublyLinkedList::insert(int data, int position) {
	if (position < 1 || position > (getLength() + 1)) {
		cout << "Invalid position" << endl;
		return;
	} else {
		node * newnode = new node;
		newnode->data = data;
		//Insertion at the head
		if (position == 1) {
			newnode->previous = nullptr;
			newnode->next = head;
			head->previous = newnode;
			head = newnode;
		} else if (position == (getLength() + 1)) {
			addNode(data);
		} else {
			//Insertion at some other position
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

void DoublyLinkedList::deleteNode(int position) {
	int length = getLength();
	if (position < 1 || position > length) {
		cout << "Invalid position" << endl;
		return;
	}
	if (position == 1) {
		node*p = head;
		head = head->next;
		if (head != nullptr)//important if the list only contains one node
			head->previous = nullptr;
		delete p;
	} else {
		if (position == length) {
			node *p = head;
			while (p->next != last) {
				p = p->next;
			}
			node *q = p->next;
			p->next = nullptr;
			last = p;
			delete q;
			return;
		} else {
			node *p = head;
			for (int i = 0; i < position - 2; ++i)
			{
				p = p->next;
			}
			node *q = p->next;
			p->next = q->next;
			q->next->previous = p;
			delete q;
			return;
		}

	}
}

void DoublyLinkedList::reverseDisplay() {
	node *p = last;
	while (p->previous != nullptr) {
		cout << p->data << " --> ";
		p = p->previous;
	}
	cout << p->data << endl;
	return;
}

void DoublyLinkedList::reverseTheList() {
	node *p = head;
	last = head;
	while (1) {
		swap(p->previous, p->next);
		if (!p->previous)
			break;
		p = p->previous;
	}
	head = p;
	return;
}


//=========================================================================


int main() {
	int a[] {1, 3, 5, 6, 7, 8, 22, 33};
	DoublyLinkedList d;
	d.create(a, 8);
	// d.display();
	// d.reverseDisplay();
	// d.insert(111, 1);
	// d.insert(999, d.getLength() + 1);
	// d.insert(55, 5);
	// d.display();
	// d.reverseDisplay();
	// d.deleteNode(5);
	// d.deleteNode(1);
	// d.deleteNode(d.getLength());
	// d.display();
	// d.reverseDisplay();
	// d.deleteNode(1);
	d.reverseTheList();
	d.display();
	return 0;
}
