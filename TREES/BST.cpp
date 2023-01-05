/*
* @Author: Mohit Pathak
* @Date:   2021-02-28 09:50:36
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-03-01 09:28:43
*/

#include<iostream>

using namespace std;

class node {
public:
	node * lchild;
	int data;
	node * rchild;
};
class bst {
	node * root;
public:
	bst() {
		root = nullptr;
	}
	void create(int *arr, int n);
	void inorder() {inorder(root);}
	void inorder(node *root);
	void preorder() {preorder(root);}
	void preorder(node *root);
	void postorder() {postorder(root);}
	void postorder(node *root);
	node * insert(int data);
	node * Rinsert(int data) {return Rinsert(root, data);};
	node * Rinsert(node * root, int data);
	node * search(int data);
	node * rsearch(node *root, int data);
	node * rsearch(int data) {return rsearch(root, data);}
	int height(node * root);
	int height() { return height(root) - 1;}
	int deleteNode(int data);
	int deleteNodeHelper(node * toswap, node * prev, node *root, int data);
};

int bst::deleteNode(int data) {
	int val = -1;
	node * temp = search(data);
	if (!temp) {
		return val;
	} else {
		node * prev = this->root;
		if (temp != this->root) {
			while (prev->lchild != temp && prev->rchild != temp) {
				if (data > prev->data) {
					prev = prev->rchild;
				} else {
					prev = prev->lchild;
				}
			}
		}
		val = deleteNodeHelper(temp, prev, temp, data);
	}
	return val;
}

int bst::deleteNodeHelper(node * toswap, node *prev, node *temp, int data) {
	int val = 0;
	if (!temp->lchild && !temp->rchild) {
		if (prev->lchild == temp) {
			prev->lchild = nullptr;
			val = temp->data;
			delete temp;
		} else {
			prev->rchild = nullptr;
			val = temp->data;
			delete temp;
		}
		return val;
	} else {
		int lheight = height(temp->lchild);
		int rheight = height(temp->rchild);
		if (lheight >= rheight) {
			prev = temp;
			temp = temp->lchild;
			while (temp->rchild != nullptr) {
				prev = temp;
				temp = temp->rchild;
			}
			swap(toswap->data, temp->data);
			toswap = temp;
			val = deleteNodeHelper(toswap, prev, temp, data);
		} else {
			prev = temp;
			temp = temp->rchild;
			while (temp->lchild != nullptr) {
				prev = temp;
				temp = temp->lchild;
			}
			swap(toswap->data, temp->data);
			toswap = temp;
			val = deleteNodeHelper(toswap, prev, temp, data);

		}
	}
	return val;
}

void bst::create(int *arr, int n) {
	node * newnode = new node;
	newnode->lchild = newnode->rchild = nullptr;
	newnode->data = arr[0];
	root = newnode;
	int j = 1;
	while (j < n) {
		node * temp = root;
		node *q = temp;
		while (temp) {
			if (arr[j] > temp->data) {
				q = temp;
				temp = temp->rchild;
			} else if (arr[j] < temp->data) {
				q = temp;
				temp = temp->lchild;
			} else {
				break;
			}
		}
		if (!temp) {
			newnode = new node;
			newnode->lchild = newnode->rchild = nullptr;
			newnode->data = arr[j];
			if (arr[j] > q->data) {
				q->rchild = newnode;
			} else {
				q->lchild = newnode;
			}
		}
		j++;
	}
}
void bst::inorder(node * root) {
	if (root) {
		inorder(root->lchild);
		cout << root->data << " ";
		inorder(root->rchild);
	}
}
void bst::preorder(node * root) {
	if (root) {
		cout << root->data << " ";
		preorder(root->lchild);
		preorder(root->rchild);
	}
}
void bst::postorder(node * root) {
	if (root) {
		postorder(root->lchild);
		postorder(root->rchild);
		cout << root->data << " ";
	}
}
node * bst::insert(int data) {
	if (!root) {
		node * val = new node;
		val->lchild = val->rchild = nullptr;
		val->data = data;
		root = val;
		return val;
	}
	node * temp = root;
	node *q = temp;
	node * val = nullptr;
	while (temp) {
		if (data > temp->data) {
			q = temp;
			temp = temp->rchild;
		} else if (data < temp->data) {
			q = temp;
			temp = temp->lchild;
		} else {
			break;
		}
	}
	if (!temp) {
		val = new node;
		val->lchild = val->rchild = nullptr;
		val->data = data;
		if (data > q->data) {
			q->rchild = val;
		} else {
			q->lchild = val;
		}
	}
	return val;
}
node * bst::Rinsert(node *root, int data) {
	if (!root) {
		node * newnode = new node;
		newnode->lchild = newnode->rchild = nullptr;
		newnode->data = data;
		this->root = newnode;
		return newnode;
	}
	node *val = nullptr;
	if (root->data > data) {
		if (root->lchild)
			val = Rinsert(root->lchild, data);
		else {
			node * newnode = new node;
			newnode->lchild = newnode->rchild = nullptr;
			newnode->data = data;
			root->lchild = newnode;
			return newnode;
		}
	} else if (root->data < data) {
		if (root->rchild)
			val = Rinsert(root->rchild, data);
		else {
			node * newnode = new node;
			newnode->lchild = newnode->rchild = nullptr;
			newnode->data = data;
			root->rchild = newnode;
			return newnode;
		}
	}
	return val;
}
node * bst::search(int data) {
	node * temp = root;
	while (temp) {
		if (temp->data == data) {
			return temp;
		} else if (temp->data > data) {
			temp = temp->lchild;
		} else {
			temp = temp->rchild;
		}
	}
	return nullptr;
}
node * bst::rsearch(node *root, int data) {
	if (!root) {
		return nullptr;
	}
	if (root->data == data) {
		return root;
	}
	node * val = nullptr;
	if (root->data > data) {
		val = rsearch(root->lchild, data);
	} else {
		val = rsearch(root->rchild, data);
	}
	return val;
}
int bst::height(node * root) {
	int val = 0;
	if (!root) {
		return val;
	} else {
		int l = height(root->lchild);
		int h = height(root->rchild);
		val = l >= h ? l + 1 : h + 1;
	}
	return val;
}




int main() {
	int arr[] {10, 5, 15, 2, 4, 3, 12, 20, 1, 18, 21};
	bst b;
	// b.create(arr, 11);
	for (int i = 0; i < 11; ++i)
	{
		cout << b.Rinsert(arr[i])->data << endl;
	}
	b.inorder();
	cout << endl;
	b.preorder();
	cout << endl;
	b.postorder();
	cout << endl;
	//test cases
	// node * temp = b.insert(19);
	// if (!temp) {
	// 	cout << "Already present!" << endl;
	// } else {
	// 	cout << "Insert successfull" << endl;
	// 	cout << temp->data << endl;
	// }
	// b.inorder();
	// cout << endl;
	// b.preorder();
	// cout << endl;
	// b.postorder();
	// cout << endl;
	// node * temp;
	// temp = b.rsearch(20);
	// if (!temp) {
	// 	cout << "Element not present";
	// } else {
	// 	cout << "Element found " << temp->data << endl;
	// }
	//====================
	cout << b.height() << endl;
	cout << b.deleteNode(10) << endl;
	cout << b.height() << endl;
	b.inorder();
	cout << endl;
	b.preorder();
	cout << endl;
	b.postorder();
	cout << endl;
	return 0;
}