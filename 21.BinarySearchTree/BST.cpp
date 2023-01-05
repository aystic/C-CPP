/*
* @Author: Mohit Pathak
* @Date:   2021-09-05 11:44:44
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-05 21:45:41
*/
#include<iostream>
#include<queue>
#include<climits>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class node {
public:
	int data;
	node*lchild;
	node*rchild;
	node(int data) {
		this->data = data;
		lchild = rchild = nullptr;
	}
};

void insert(node*&root, int data) {
	if (!root) {
		root = new node(data);
		return;
	}
	if (data <= root->data) {
		insert(root->lchild, data);
		return;
	}
	insert(root->rchild, data);
	return;
}

node* buildTree() {
	int data;
	cin >> data;
	node*root = nullptr;
	while (data != -1) {
		insert(root, data);
		cin >> data;
	}
	return root;
}

void inorder(node*root) {
	if (!root)return;
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
	return;
}

queue<node*> q;
void levelOrder(node*root) {
	if (!root)return;
	q.push(root);
	q.push(nullptr);
	while (!q.empty()) {
		node*temp = q.front();
		q.pop();
		if (!temp) {
			cout << endll;
			if (!q.empty())
				q.push(nullptr);
			continue;
		}
		cout << temp->data << " ";
		if (temp->lchild) {
			q.push(temp->lchild);
		}
		if (temp->rchild) {
			q.push(temp->rchild);
		}
	}
	return;
}

bool search(node*root, int data) {
	if (!root)return false;
	if (root->data == data)return true;
	if (data <= root->data)return search(root->lchild, data);
	return search(root->rchild, data);
}

node* deleteNodeInBST(node*&root, int data) {
	if (!root)return nullptr;
	if (data < root->data) {
		root->lchild = deleteNodeInBST(root->lchild, data);
		return root;
	} else if (data > root->data) {
		root->rchild = deleteNodeInBST(root->rchild, data);
		return root;
	}
	//case 1 no children;
	if (!root->lchild and !root->rchild) {
		delete root;
		return nullptr;
	}
	//case 2 one children
	if (root->lchild and !root->rchild) { //only lchild exist
		node*temp = root->lchild;
		delete root;
		return temp;
	}
	if (root->rchild and !root->lchild) { //only rchild exist
		node*temp = root->rchild;
		delete root;
		return temp;
	}

	//case 3 when both the children exist
	node *temp = root->rchild;
	while (temp->lchild) {
		temp = temp->lchild;
	}
	root->data = temp->data;
	root->rchild = deleteNodeInBST(root->rchild, temp->data);
	return root;
}

bool checkForBST(node*root, int min = INT_MIN, int max = INT_MAX) {
	if (!root)return true;
	if (root->data > min and root->data <= max) {
		bool l = checkForBST(root->lchild, min, root->data);
		if (l) {
			return checkForBST(root->rchild, root->data, max);
		}
		return false;
	}
	return false;
}

class LL {
public:
	node*head;
	node*tail;
	LL() {
		head = tail = nullptr;
	}
};
LL flattenBST(node*&root) {
	LL l;
	if (!root) {
		return l;
	}
	//case 1 no left and right child
	if (!root->lchild and !root->rchild) {
		l.head = root;
		l.tail = root;
		return l;
	}
	//case 2 when only lchild exists
	if (root->lchild and !root->rchild) {
		LL left = flattenBST(root->lchild);
		left.tail->rchild = root;
		left.tail = root;
		return left;
	}
	//case 3 when only rchild exists
	if (root->rchild and !root->lchild) {
		LL right = flattenBST(root->rchild);
		root->rchild = right.head;
		right.head->lchild = root;
		right.head = root;
		return right;
	}
	//case 4 when both the child exist
	LL left = flattenBST(root->lchild);
	LL right = flattenBST(root->rchild);
	l.head = left.head;
	l.tail = right.tail;
	left.tail->rchild = root;
	root->lchild = left.tail;
	right.head->lchild = root;
	root->rchild = right.head;
	return l;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================
	node*root = buildTree();
	inorder(root);
	cout << endll;
	levelOrder(root);
	cout << endll;
	// cout << checkForBST(root) << endll;
	LL l = flattenBST(root);
	node*ll = l.head;
	while (ll) {
		cout << ll->data << " --> ";
		ll = ll->rchild;
	}
	cout << endll;
	ll = l.tail;
	while (ll) {
		cout << ll->data << " --> ";
		ll = ll->lchild;
	}
	return 0;
}

