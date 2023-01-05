/*
* @Author: Mohit Pathak
* @Date:   2021-02-15 19:42:25
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-22 01:30:16
*/

#include<iostream>

using namespace std;


//=============================================
class node {
public:
	int data;
	node* next;
};
class linkedlist {
	node* head;
	node* last;
	int length;
public:
	linkedlist() {
		head = nullptr;
		last = head;
		length = 0;
	}
	void addNode(int data);
	void create(int* arr, int n);
	void display();
	int getlength() { return length;}
	node * gethead() {return head;}
	void insertNode(int data, int position);
	void setHead(node * p) {head = p;}
	void deleteNode(int data);
	void insertSorted(int data);
	void isSorted();
	void removeDuplicates();
	void reverseUsingArray();
	void reverseWithoutArray();
	void reveresUsingSlidingPointers();
	node * reverseUsingRecursion(node * p);
	void concatanate(linkedlist* secondary);
	linkedlist * merge(linkedlist * primary, linkedlist* secondary);
	void createloop(int position);
	bool isloop();
	void findmid();
	~linkedlist(){
		if(!head)return;
		node*temp;
		while(head){
			temp=head;
			head=head->next;
			delete temp;
		}
	}
};

void linkedlist::create(int *arr, int n) {
	for (int i = 0; i < n; ++i)
	{
		addNode(arr[i]);
	}
}

void linkedlist::addNode(int data) {
	node * newnode = new node;
	newnode->data = data;
	newnode->next = nullptr;
	if (head == nullptr) {
		head = newnode;
		last = newnode;
	} else {
		last->next = newnode;
		last = newnode;
	}
	length++;
}

void linkedlist::display() {
	node* counter = head;
	if (length == 0) {
		cout << "Linked list is empty!" << endl;
		return;
	}
	while (counter->next != nullptr) {
		cout << counter->data << " --> ";
		counter = counter->next;
	}
	cout << counter->data << endl;
	return;
}

void linkedlist::deleteNode(int data) {
	node * q = nullptr;
	node* p = head;
	if (!p) {
		cout << "List empty!" << endl;
		return ;
	} else {
		int count = 1;
		while (p) {
			if (p->data == data)
				break;
			count++;
			q = p;
			p = p->next;
		}
		if (!p) {
			cout << "Element not found!" << endl;
			return;
		}
		if (!q) {
			/*case when the node to be deleted is the first node where
			q is null and p points to the first node*/
			head = p->next;
			delete p;
			cout << data << " deleted!" << endl;
			length--;
			display();
			return;
		}
		if (count == length)
			last = q;
		q->next = p->next;
		delete p;
		cout << data << " deleted!" << endl;
		length--;
		display();
		return;
	}
}

void linkedlist::insertNode(int data, int position) {
	if (position < 1 || position > length + 1) {
		cout << "Invalid position!" << endl;
		return ;
	} else {
		int count = 1;
		node*p = head;
		if (position == 1) {
			node * newnode = new node;
			newnode->data = data;
			newnode->next = head;
			head = newnode;
			if (newnode->next == nullptr) {
				last = newnode;
			}
			display();
			length++;
			return;
		} else {
			if (position == length + 1) {
				node * newnode = new node;
				newnode->data = data;
				newnode->next = nullptr;
				last->next = newnode;
				last = newnode;
				length++;
				display();
				return;
			}
			while (count != position - 1) {
				count++;
				p = p->next;
			}
			node * newnode = new node;
			newnode->data = data;
			newnode->next = p->next;
			p->next = newnode;
			length++;
			display();
			return;
		}
	}
}

void linkedlist::insertSorted(int data) {
	node * p = head;
	node *q = p;
	//case when the list is empty
	if (!p) {
		addNode(data);
		return;
	}
	while (p->data < data) {
		q = p;
		p = p->next;
		if (p == nullptr)//case when the element to be inserted is the largest, Insertion at last
			break;
	}
	if (!p) {
		addNode(data);//insertion at last p=null and q=last node
		return;
	}
	node* newnode = new node;
	newnode->data = data;
	newnode->next = p;
	if (p == head) {//case when the element to be inserted is the smallest element
		//while the list is non empty
		head = newnode;
	} else//case for insertion in between
		q->next = newnode;
	length++;
	return;
}

void linkedlist::isSorted() {
	node *p = head;
	if (!p) {
		cout << "List is empty!" << endl;
		return;
	}
	while (p->next != nullptr) {
		if (p->data > p->next->data) {
			cout << "List is not sorted" << endl;
			return;
		}
		p = p->next;
	}
	cout << "List is sorted!" << endl;
	return ;
}

void linkedlist::removeDuplicates() {
	node *p = head;
	node *q = p;
	if (!p) {
		cout << "List is empty!" << endl;
		return;
	}
	while (p->next != nullptr) {
		if (p->data == p->next->data) {
			p = p->next;
			q->next = p->next;
			delete p;
			length--;
			p = q;
		} else {
			p = p->next;
			q = p;
		}
	}
	display();
	return;
}

void linkedlist::reverseUsingArray() {
	int arr[length];//auxialliary array
	int i = 0;
	node*p = head;
	while (p) {//copying elements from the linked list into the array
		arr[i] = p->data;
		p = p->next;
		i++;
	}
	i--;
	p = head;
	while (p) {
		//copying elements from the array into linked list in reverse order
		p->data = arr[i];
		p = p->next;
		i--;
	}
	display();
	return;
}

void linkedlist::reverseWithoutArray() {
	/*
	linked list = 1 -> 2 -> 3 -> 4
	pass1 : 2->3->4->1
	pass2 : 3->4->2->1
	pass3 : 4->3->2->1

	*/
	int traverseCount = length - 1;
	node*p = head, *q = p->next;
	while (traverseCount >= 0) {
		p = head;
		q = p->next;
		int n = traverseCount;
		while (n--) {
			swap(p->data, q->data);
			p = q;
			q = q->next;
		}
		traverseCount--;
	}
	display();
	return;

}

void linkedlist::reveresUsingSlidingPointers() {
	node *p = head, *q = nullptr, *r = nullptr;
	while (p) {
		r = q;
		q = p;
		p = p->next; //sliding the pointers
		//reversing the middle link(link pointed by q {<-r<-q p->})
		q->next = r;
	}
	head = q;
	display();
	return;
}

node * linkedlist::reverseUsingRecursion(node * p) {
	if (p->next == nullptr) {
		head = p;
		return p;
	}
	reverseUsingRecursion(p->next)->next = p;
	p->next = nullptr;
	return p;
}

void linkedlist::concatanate(linkedlist * secondary) {
	node *p = head;
	while (p->next != nullptr) {
		p = p->next;
	}
	p->next = secondary->gethead();
	length = length + secondary->length;
	delete secondary;
	display();
	return;

}

linkedlist * linkedlist::merge(linkedlist* primary, linkedlist* secondary) {
	node *p, *q;
	node* r;
	linkedlist * merged;
	if (head->data < secondary->gethead()->data) {
		p = head;
		q = head->next;
		p->next = nullptr;
		r = secondary->gethead();
		merged = primary;
	} else {
		p = secondary->gethead();
		q = p->next;
		p->next = nullptr;
		r = head;
		merged = secondary;
	}
	while (q && r) {
		if (q->data <= r->data) {
			p->next = q;
			q = q->next;
			p = p->next;
			p->next = nullptr;
		} else {
			p->next = r;
			r = r->next;
			p = p->next;
			p->next = nullptr;
		}
	}
	if (q) {
		p->next = q;
	}
	if (r) {
		p->next = r;
	}
	merged->display();
	merged->length = primary->length + secondary->length;
	return merged;
}

void linkedlist::createloop(int position) {
	node * p = head;
	int count = 1;
	while (count < position) {
		p = p->next;
		count++;
	}
	last->next = p;
}

bool linkedlist::isloop() {
	node *p = head, *q = head;
	while (p && p->next) {
		p = p->next->next;
		q = q->next;
		if (p == q) {
			return true;
		}
	}
	return false;

}

void linkedlist::findmid() {
	node *p = head, *q = head;
	if (!p) {
		cout << "List is empty!" << endl;
		return;
	}
	while (p) {
		p = p->next;
		if (p) {
			p = p->next;
		}
		if (p) {
			q = q->next;
		}
	}
	cout << "Middle element is " << q->data << endl;
	return;
}



//====================================
void display(linkedlist *l) {
	if (l->getlength() == 0) {
		cout << "Linkedlist is empty!" << endl;
		return ;
	} else {
		node * counter = l->gethead();
		while (counter != nullptr) {
			cout << counter->data << " --> ";
			counter = counter->next;
		}
		return ;
	}
}

void rDisplay(node *n) {
	if (n == nullptr) {
		return;
	}
	cout << n->data << " --> ";
	rDisplay(n->next);
}

void reverseRecursiveDisplay(node *n) {
	if (n == nullptr) {
		return;
	}
	reverseRecursiveDisplay(n->next);
	cout << n->data << " --> ";
}

int noOfElements(node*n) {
	if (n == nullptr)
		return 0;
	return noOfElements(n->next) + 1;
}

int noOfElementsUsingLoops(node *n) {
	if (n == nullptr) {
		return 0;
	} else {
		int count = 0;
		while (n != nullptr) {
			count++;
			n = n->next;
		}
		return count;
	}
}

int sumOfAllNodes(node * p) {
	if (p == nullptr)
		return 0;
	else {
		int sum = 0;
		while (p != nullptr) {
			sum += p->data;
			p = p->next;
		}
		return sum;
	}
}

int sumOfAllNodesUsingRecursion(node * n) {
	if (n == nullptr)
		return 0;
	else {
		return n->data + sumOfAllNodesUsingRecursion(n->next);
	}
}

void searching(int data, node* p) {
	if (!p) {
		cout << "List empty!" << endl;
		return ;
	} else {
		int count = 1;
		while (p) {
			if (p->data == data)
				break;
			count++;
			p = p->next;
		}
		if (p) {
			cout << "Element " << data << " is present at the node " << count << endl;
			return;
		} else {
			cout << "Element not found!" << endl;
			return ;
		}
	}
}

node * rSearching(int data, node *p) {
	if (!p) {
		return nullptr;
	} else {
		if (p->data == data)
			return p;
		return rSearching(data, p->next);
	}

}

void searchingMovetoHead(int data, linkedlist* l) {
	node * q = nullptr;
	node* p = l->gethead();
	if (!p) {
		cout << "List empty!" << endl;
		return ;
	} else {
		int count = 1;
		while (p) {
			if (p->data == data)
				break;
			count++;
			q = p;
			p = p->next;
		}
		if (p) {
			cout << "Element " << data << " is present at the node " << count << endl;
		} else {
			cout << "Element not found!" << endl;
			return;
		}
		if (count > 1) {
			q->next = p->next;
			p->next = l->gethead();
			l->setHead(p);
		}
		return;
	}
}

void findmax(node *p) {
	if (!p) {
		cout << "List empty" << endl;
		return;
	} else {
		int max = p->data;
		while (p) {
			if (max < p->data)
				max = p->data;
			p = p->next;
		}
		cout << "Max Element is " << max << endl;
		return;
	}
}

void findmin(node *p) {
	if (!p) {
		cout << "List empty" << endl;
		return;
	} else {
		int min = p->data;
		while (p) {
			if (min > p->data)
				min = p->data;
			p = p->next;
		}
		cout << "min Element is " << min << endl;
		return;
	}
}



int main() {
	linkedlist l;
	// l.display();
	// cout << l.getlength() << endl;
	l.addNode(1);
	l.addNode(2);
	l.addNode(3);
	l.addNode(4);
	l.addNode(5);
	l.addNode(7);
	l.addNode(6);
	l.display();
	// l.insertNode(1, 1);
	// l.insertNode(2, 2);
	// l.insertNode(3, 3);
	// l.insertNode(4, 4);
	// l.insertNode(5, 5);
	// l.insertNode(7, 6);
	// l.insertNode(6, 7);
	// l.display();
	// cout << l.getlength() << endl;
	// cout << "==================================" << endl;
	// display(&l);
	// cout << endl;
	// rDisplay(l.gethead());
	// cout << endl;
	// reverseRecursiveDisplay(l.gethead());
	// cout << endl;
	// cout << "==================================" << endl;
	// cout << noOfElements(l.gethead()) << endl;
	// cout << noOfElementsUsingLoops(l.gethead()) << endl;
	// cout << sumOfAllNodes(l.gethead()) << endl;
	// cout << sumOfAllNodesUsingRecursion(l.gethead()) << endl;
	// cout << "==================================" << endl;
	// findmax(l.gethead());
	// findmin(l.gethead());
	// cout << "==================================" << endl;
	// searching(7, l.gethead());
	// searching(-1, l.gethead());
	// cout << rSearching(7, l.gethead())->data << endl;
	// if (!rSearching(-1, l.gethead()))
	// 	cout << "Element not found!" << endl;
	// searchingMovetoHead(7, &l);
	// searchingMovetoHead(7, &l);
	// searchingMovetoHead(-1, &l);
	// l.display();
	// cout << "==================================" << endl;
	// l.deleteNode(7);
	// l.deleteNode(1);
	// l.insertNode(7, l.getlength() - 1);
	// cout << l.getlength() << endl;
	// l.insertNode(1, 1);
	// cout << l.getlength() << endl;
	// l.insertNode(8, l.getlength() + 1);
	// cout << l.getlength() << endl;

	// l.insertNode(8, 10);
	// cout << l.getlength() << endl;

	// linkedlist l;

	// l.display();
	// l.insertSorted(1);
	// l.display();
	// l.insertSorted(3);
	// l.display();
	// l.insertSorted(27);
	// l.display();
	// l.insertSorted(4);
	// l.display();
	// l.insertSorted(2);
	// l.display();
	// l.insertSorted(2);
	// l.display();
	// l.insertSorted(16);
	// l.display();
	// l.insertSorted(5);
	// l.display();
	// l.insertSorted(5);
	// l.display();
	// l.insertSorted(5);
	// l.display();
	// l.insertSorted(9);
	// l.display();
	// l.insertSorted(-10);
	// l.display();
	// cout << l.getlength() << endl;
	// cout << sizeof(l) << endl;
	// l.isSorted();
	// cout << "=======================" << endl;
	// // l.insertNode(-8, 5);
	// // l.display();
	// // l.isSorted();

	// l.removeDuplicates();
	// cout << sizeof(l) << endl;
	// cout << l.getlength() << endl;

	// cout << "==================================" << endl;
	// // cout << "Reversing the linked list using an array" << endl;
	// // l.reverseUsingArray();
	// // cout << "Reversing the linked list without using an array or changing the links but by continuously swapping two elements at a time" << endl;
	// // l.reverseWithoutArray();
	// // cout << "Reversing the linked list using sliding pointers" << endl;
	// // l.reveresUsingSlidingPointers();
	// // cout << "Reversing the linked list using recursion" << endl;
	// // l.reverseUsingRecursion(l.gethead());
	// // l.display();

	linkedlist *p = new linkedlist;
	p->addNode(-9);
	p->addNode(1);
	p->addNode(10);
	p->addNode(23);
	p->display();
	// l.concatanate(p);
	// cout << l.getlength() << endl;
	linkedlist * merged = l.merge(&l, p);
	cout << merged->getlength() << endl;

	// linkedlist l;
	// l.addNode(1);
	// l.addNode(2);
	// l.addNode(3);
	// l.addNode(4);
	// l.addNode(5);
	// l.addNode(7);
	// l.addNode(6);
	// l.createloop(6);
	// if (l.isloop())
	// 	cout << "The linkedList contains loop" << endl;
	// else {
	// 	l.display();
	// }


	// linkedlist l;
	// int arr[] {11, 22, 33, 44, 55, 66, 77, 88, 99, 0};
	// l.create(arr, 10);
	// l.display();
	// l.findmid();
	return 0;
}
