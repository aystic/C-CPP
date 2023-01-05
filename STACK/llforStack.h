//===========Linked List==================
class node {
public:
	int data;
	node * next;
};
class linkedlist {
	node * head;
public:
	linkedlist() {
		head = nullptr;
	}
	int deletenode();
	void create(int* arr, int n);
	void insertnode(int data);
	int getnode(int position);
	void addnode(int data);
	node * gethead() {return head;}
	void sethead(node * head) { this->head = head;}
};

void linkedlist::addnode(int data) {
	node * newnode = new node;
	newnode->data = data;
	newnode->next = head;
	head = newnode;
}
void linkedlist::insertnode(int data) {
	node * newnode = new node;
	newnode->data = data;
	if (!head) {
		head = newnode;
		newnode->next = nullptr;
	} else {
		newnode->next = head;
		head = newnode;
	}
}
void linkedlist::create(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		addnode(arr[i]);
	}
}

int linkedlist::deletenode() {
	int val = -1;
	if (!head) {
		return val;;
	} else {
		node *q = head;
		head = head->next;
		val = q->data;
		delete q;
	}
	return val;
}

int linkedlist::getnode(int position) {
	node *p = head;
	for (int i = 0; i < position - 1; ++i)
	{
		p = p->next;
	}
	return p->data;

}
//=========================================