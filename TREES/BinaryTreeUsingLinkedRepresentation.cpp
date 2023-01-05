/*
* @Author: Mohit Pathak
* @Date:   2021-02-27 07:44:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-28 08:13:01
*/

#include<iostream>
using namespace std;

class node {
public:
	node* lchild;
	int data;
	node * rchild;
};

class stnode {
public:
	node *data;
	stnode* next;
};

class stack {
	stnode* top;
public:
	stack() {
		top = nullptr;
	}
	void push(node * data);
	node * pop();
	bool isempty() {return top == nullptr ? true : false;}
};
void stack::push(node * root) {
	stnode * newnode = new stnode;
	newnode->data = root;
	if (!isempty()) {
		newnode->next = top;
		top = newnode;
	} else {
		newnode->next = nullptr;
		top = newnode;
	}
}
node * stack::pop() {
	node * val = nullptr;
	if (!isempty()) {
		stnode* s = top;
		top = top->next;
		val = s->data;
		delete s;
		return val;
	}
	return val;
}




class qnode {
public:
	node * data;
	qnode* next;
};

class queue {
	qnode* front;
	qnode* rear;
public:
	queue() {
		front = rear = nullptr;
	}
	bool isempty() {
		return front == nullptr ? true : false;
	}
	void enqueue(node * data) {
		qnode* newnode = new qnode;
		newnode->data = data;
		newnode->next = nullptr;
		if (isempty()) {
			front = rear = newnode;
		} else {
			rear->next = newnode;
			rear = newnode;
		}
	}
	node * dequeue() {
		node * val = nullptr;
		if (!isempty()) {
			qnode *p = front;
			front = front->next;
			val = p->data;
			delete p;
			return val;
		}
		return val;
	}
};

class binarytree {
	node * root;
public:
	binarytree() {
		root = nullptr;
	}
	void create(int *arr);
	void display();
	void inorder() {inorder(root);} //dummy function
	void inorder(node * n);
	void preorder() {preorder(root);} //dummy function
	void preorder(node *n);
	void postorder() {postorder(root);}; //dummy function
	void postorder(node *n);
	void levelorder();
	//Stack is used
	void preorderUsingLoops() {preorderUsingLoops(root);}
	void preorderUsingLoops(node * root);
	void inorderUsingLoops() {inorderUsingLoops(root);}
	void inorderUsingLoops(node * root);
	void postorderUsingLoops() {postorderUsingLoops(root);}
	void postorderUsingLoops(node * root);

	int countNodes() {return countNodes(root);}
	int countNodes(node *root);
	int countTwoDegreeNodes() {return countTwoDegreeNodes(root);}
	int countTwoDegreeNodes(node * root);
	int countOneDegreeNodes() {return countOneDegreeNodes(root);}
	int countOneDegreeNodes(node * root);
	int countZeroDegreeNodes() {return countZeroDegreeNodes(root);}
	int countZeroDegreeNodes(node * root);
	int sumOfNodes() {return sumOfNodes(root);}
	int sumOfNodes(node * root);
	int height() {return height(root);}
	int height(node * root);
};
void binarytree::create(int *arr) {
	node * newnode = new node;
	newnode->lchild = newnode->rchild = nullptr;
	newnode->data = arr[0];
	queue *q = new queue;
	root = newnode;
	q->enqueue(newnode);
	int j = 1;
	while (!q->isempty()) {
		node *temp = q->dequeue();
		if (arr[j] != -1) {
			node *left = new node;
			left->lchild = left->rchild = nullptr;
			left->data = arr[j];
			temp->lchild = left;
			q->enqueue(left);
		}
		j++;
		if (arr[j] != -1) {
			node *right = new node;
			right->lchild = right->rchild = nullptr;
			right->data = arr[j];
			temp->rchild = right;
			q->enqueue(right);
		}
		j++;
	}
	delete q;
}

void binarytree::display() {
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
	cout << endl;
	levelorder();
	cout << endl;
}

void binarytree::preorder(node * n) {
	if (n) {
		cout << n->data << " ";
		preorder(n->lchild);
		preorder(n->rchild);
	}
}

void binarytree::inorder(node * n) {
	if (n) {
		inorder(n->lchild);
		cout << n->data << " ";
		inorder(n->rchild);
	}
}

void binarytree::postorder(node * n) {
	if (n) {
		postorder(n->lchild);
		postorder(n->rchild);
		cout << n->data << " ";
	}
}

void binarytree::levelorder() {
	queue *q = new queue;
	cout << root->data << " ";
	q->enqueue(root);
	while (!q->isempty()) {
		node * temp = q->dequeue();
		if (temp->lchild) {
			cout << temp->lchild->data << " ";
			q->enqueue(temp->lchild);
		}
		if (temp->rchild) {
			cout << temp->rchild->data << " ";
			q->enqueue(temp->rchild);
		}
	}
	delete q;
}

void binarytree::preorderUsingLoops(node * root) {
	stack *st = new stack;
	node * temp = root;
	while (temp != nullptr || !st->isempty()) {
		if (temp != nullptr) {
			cout << temp->data << " ";
			st->push(temp);
			temp = temp->lchild;
		}
		if (temp == nullptr) {
			temp = st->pop();
			temp = temp->rchild;
		}
	}
	cout << endl;
	delete st;
}

void binarytree::inorderUsingLoops(node *root) {
	stack *st = new stack;
	node * temp = root;
	while (temp || !st->isempty()) {
		if (temp) {
			st->push(temp);
			temp = temp->lchild;
		}
		if (!temp) {
			temp = st->pop();
			cout << temp->data << " ";
			temp = temp->rchild;
		}
	}
	cout << endl;
	delete st;
}

void binarytree::postorderUsingLoops(node * root) {
	stack * st = new stack;
	node * temp = root;
	while (temp || !st->isempty()) {
		if (temp) {
			st->push(temp);
			temp = temp->lchild;
		}
		if (!temp) {
			temp = st->pop();
			if (temp > 0) {
				st->push((node *)( - 1 * (long long int)temp));
				temp = temp->rchild;
			} else {
				temp = (node *)(-1 * (long long int)temp);
				cout <<  temp->data << " ";
				temp = nullptr;
				// temp = temp->rchild;
			}
		}
	}
}

int binarytree::countNodes(node * root) {
	if (!root)
		return 0;
	return countNodes(root->lchild) + countNodes(root->rchild) + 1;
}

int binarytree::countTwoDegreeNodes(node *root) {
	if (!root)
		return 0;
	return (root->lchild && root->rchild) ? countTwoDegreeNodes(root->lchild) + countTwoDegreeNodes(root->rchild) + 1 : countTwoDegreeNodes(root->lchild) + countTwoDegreeNodes(root->rchild);
}

int binarytree::countOneDegreeNodes(node *root) {
	if (!root)
		return 0;
	return (root->lchild != nullptr) ^ (root->rchild != nullptr) ? countOneDegreeNodes(root->lchild) + countOneDegreeNodes(root->rchild) + 1 : countOneDegreeNodes(root->lchild) + countOneDegreeNodes(root->rchild);
}

int binarytree::countZeroDegreeNodes(node *root) {
	if (!root)
		return 0;
	return (root->lchild || root->rchild) == false && (root->lchild && root->rchild) == false ? countZeroDegreeNodes(root->lchild) + countZeroDegreeNodes(root->rchild) + 1 : countZeroDegreeNodes(root->lchild) + countZeroDegreeNodes(root->rchild);
}

int binarytree::sumOfNodes(node *root) {
	if (!root)
		return 0;
	return sumOfNodes(root->lchild) + sumOfNodes(root->rchild) + root->data;
}

int binarytree::height(node *root) {
	if ((!root->lchild && !root->rchild)) {
		return 0;
	}
	if (!root->lchild) {
		return height(root->rchild) + 1;
	}
	if (!root->rchild) {
		return height(root->lchild) + 1;
	}
	int l = height(root->lchild);
	int r = height(root->rchild);
	return l >= r ? l + 1 : r + 1;
}

int main() {
	int arr[] {1, 2, 3, 4, 5, -1, 6, 7, 8, -1, -1, 9, 10, -1, -1, -1, -1, -1, -1, -1, -1};
	binarytree bt;
	bt.create(arr);
	bt.preorder();
	cout << endl;
	bt.inorder();
	cout << endl;
	bt.postorder();
	cout << endl;
	cout << "==============================" << endl;
	bt.preorderUsingLoops();
	bt.inorderUsingLoops();
	// bt.postorderUsingLoops();
	cout << "Nodes :" << bt.countNodes() << endl;
	cout << "Two Degree Nodes :" << bt.countTwoDegreeNodes() << endl;
	cout << "One Degree Nodes :" << bt.countOneDegreeNodes() << endl;
	cout << "Leaf Nodes :" << bt.countZeroDegreeNodes() << endl;
	cout << "Sum of Nodes :" << bt.sumOfNodes() << endl;
	cout << "height :" << bt.height() << endl;
	return 0;
}