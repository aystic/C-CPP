/*
* @Author: Mohit Pathak
* @Date:   2021-03-03 11:58:29
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-03-04 16:47:06
*/

#include<iostream>
using namespace std;

//avl tree node
class node {
public:
	node* lchild;
	int data;
	node* rchild;
};

//=============stack======================
class stackNode {
public:
	node * address;
	stackNode* next;
};
class stack {
	stackNode * top;
	int length;
public:
	stack() {
		top = nullptr;
		length = 0;
	}
	void push(node *data) {
		stackNode* newnode = new stackNode;
		newnode->address = data;
		if (isempty()) {
			top = newnode;
			newnode->next = nullptr;
		} else {
			newnode->next = top;
			top = newnode;
		}
		length++;
	}
	node * pop() {
		node * val = nullptr;
		if (!isempty()) {
			val = top->address;
			stackNode * temp = top;
			top = top->next;
			delete temp;
			length--;
		}
		return val;
	}
	bool isempty() {
		return top == nullptr ? true : false;
	}
	void deletestack() {
		while (!isempty()) {
			stackNode * temp = top;
			top = top->next;
			delete temp;
		}
	}
};
stack *st = new stack;
//=========================================

//avl tree class
class avl {
	node* root;
public:
	avl() {
		root = nullptr;
	}
	void insert(int data);
	void create(int *arr, int n);
	int height(node * p);
	int notbalanced(node *p, int data);
	void rotate(node * p);
	int balancefactor(node * p);
	void ll(node*p, int data);
	void rr(node *p, int data);
	void rl(node *p, int data);
	void lr(node *p, int data);
	void preorder(node * root);
	void inorder(node * root);
	void postorder(node * root);

	//dummy functions
	int height() {return height(root);}
	void preorder() {preorder(root);}
	void inorder() {inorder(root);}
	void postorder() {postorder(root);}
};

void avl::preorder(node*root) {
	if (root) {
		cout << root->data << " ";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}

void avl::inorder(node*root) {
	if (root) {
		inorder(root->lchild);
		cout << root->data << " ";
		inorder(root->rchild);
	}
}

void avl::postorder(node*root) {
	if (root) {
		postorder(root->lchild);
		postorder(root->rchild);
		cout << root->data << " ";
	}
}

void avl::ll(node *p, int data) {
	node * temp = p->lchild;
	node * parent = nullptr;
	node * rightchild = temp->rchild;
	if (!st->isempty()) {
		parent = st->pop();
	}
	temp->rchild = p;
	if (rightchild)
		p->lchild = rightchild;
	else
		p->lchild = nullptr;
	if (!parent) {
		root = temp;
	}
	else {
		if (data > parent->data) {
			parent->rchild = temp;
		} else {
			parent->lchild = temp;
		}
	}
	cout << root->data << " " << parent->data << " " << temp->data << endl;
}

void avl::rr(node *p, int data) {
	node * temp = p->rchild;
	node * leftchild = temp->lchild;
	node * parent = nullptr;
	if (!st->isempty()) {
		parent = st->pop();
	}
	temp->lchild = p;
	if (leftchild)
		p->rchild = leftchild;
	else
		p->rchild = nullptr;
	if (!parent) {
		root = temp;
	} else {
		if (data > parent->data) {
			parent->rchild = temp;
		} else {
			parent->lchild = temp;
		}
	}
}

void avl::lr(node *p, int data) {
	node * prev = p->lchild;
	node *temp = prev->rchild;
	node * leftchild = temp->lchild, *rightchild = temp->rchild;
	node * parent = nullptr;
	if (!st->isempty()) {
		parent = st->pop();
	}
	temp->lchild = prev;
	if (leftchild)
		prev->rchild = leftchild;
	else
		prev->rchild = nullptr;
	temp->rchild = p;
	if (rightchild)
		p->lchild = rightchild;
	else
		p->lchild = nullptr;
	if (!parent) {
		root = temp;
	} else {
		if (data > parent->data) {
			parent->rchild = temp;
		} else {
			parent->lchild = temp;
		}
	}
}

void avl::rl(node *p, int data) {
	node * prev = p->rchild;
	node *temp = prev->lchild;
	node * leftchild = temp->lchild, *rightchild = temp->rchild;
	node * parent = nullptr;
	if (!st->isempty()) {
		parent = st->pop();
	}
	temp->lchild = p;
	if (leftchild)
		p->rchild = leftchild;
	else
		p->rchild = nullptr;
	temp->rchild = prev;
	if (rightchild)
		prev->lchild = rightchild;
	else
		prev->lchild = nullptr;
	if (!parent) {
		root = temp;
	} else {
		if (data > parent->data) {
			parent->rchild = temp;
		} else {
			parent->lchild = temp;
		}
	}
}

int avl::height(node *p) {
	if (!p || (!p->lchild && !p->rchild)) {
		return 0;
	}
	int lheight = height(p->lchild);
	int rheight = height(p->rchild);
	return lheight >= rheight ? lheight + 1 : rheight + 1;
}

int avl::balancefactor(node *p) {
	int lheight = height(p->lchild);
	int rheight = height(p->rchild);
	if (!p->lchild) {
		lheight = 0;
	} else {
		lheight++;
	}
	if (!p->rchild) {
		rheight = 0;
	} else {
		rheight++;
	}
	return (lheight - rheight);
}

int avl::notbalanced(node *p, int data) {
	// if (balancefactor(p) == 2 || balancefactor(p) == -2) {
	// 	if (data > p->data) {
	// 		//rl or rr
	// 		if (data > p->rchild->data) {
	// 			//rr
	// 			return 2;
	// 		} else {
	// 			//rl
	// 			return 4;
	// 		}
	// 	} else {
	// 		//ll or lr
	// 		if (data > p->lchild->data) {
	// 			//lr
	// 			return 3;
	// 		} else {
	// 			//ll
	// 			return 1;
	// 		}
	// 	}
	// }
	if (balancefactor(p) == 2) {
		if (balancefactor(p->lchild) == 1) {
			return 1;//ll
		} else {
			return 3;//lr
		}
	} else if (balancefactor(p) == -2) {
		if (balancefactor(p->rchild) == 1) {
			return 4;//rl
		} else {
			return 2;//rr
		}
	}
	return 0;
}

void avl::insert(int data) {
	// st = new stack;
	if (!root) {
		root = new node;
		root->lchild = root->rchild = nullptr;
		root->data = data;
		// root->height = 0;
		return;
	} else {
		// insertion steps
		node * temp = root, *tail = temp;
		while (temp) {
			if (data > temp->data) {
				tail = temp;
				temp = temp->rchild;
				st->push(tail);
			} else if (data < temp->data) {
				tail = temp;
				temp = temp->lchild;
				st->push(tail);
			} else {
				st->deletestack();
				return;
			}
		}
		//creation and linking of newnode
		temp = new node;
		temp->lchild = temp->rchild = nullptr;
		temp->data = data;
		cout << temp->data << " " << tail->data << endl;
		if (data > tail->data) {
			tail->rchild = temp;
			// cout << tail->data << "Linked" << endl;
		} else {
			tail->lchild = temp;
			// cout << tail->data << "Linked" << endl;

		}
	}
	//Balancing the tree if required
	node * temp = st->pop();
	if (!st->isempty() || (temp->lchild == nullptr || temp->rchild == nullptr)) {
		do {
			int type = notbalanced(temp, data);
			// cout << type << endl;
			if (type) {
				if (type == 1) {
					cout << "ll " << temp->data << endl;
					ll(temp, data);
				} else if (type == 2) {
					cout << "rr " << temp->data << endl;
					rr(temp, data);
				} else if (type == 3) {
					cout << "lr " << temp->data << endl;
					lr(temp, data);
				} else {
					cout << "rl " << temp->data << endl;
					rl(temp, data);
				}
				break;
			}
			if (st->isempty())
				break;
			temp = st->pop();
		} while (1) ;
	}
	//update the height

	st->deletestack();
	return ;
}

int main() {
	int arr[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	int count = 15;
	avl a;
	for (int i = 0; i < count; ++i)
	{
		a.insert(arr[i]);
	}
	a.preorder();
	cout << endl;
	a.inorder();
	cout << endl;
	a.postorder();
	cout << endl;
	cout << a.height() << endl;
	return 0;
}