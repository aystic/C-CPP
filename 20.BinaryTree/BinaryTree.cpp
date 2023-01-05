/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 12:45:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-05 10:40:09
*/

#include<iostream>
#include<queue>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class node {
public:
	int data;
	node* lchild;
	node* rchild;
	node(int data) {
		this->data = data;
		lchild = rchild = nullptr;
	}
};

node* buildTree() { //returns the root node
	int data;
	cin >> data;
	if (data == -1) { //no node
		return nullptr;
	}
	node*root = new node(data);//building the root
	root->lchild = buildTree();//building the left child
	root->rchild = buildTree();//building the right child
	return root;
}

void preorder(node*root) {
	if (!root)return;
	cout << root->data << " ";
	preorder(root->lchild);
	preorder(root->rchild);
	return;
}

void inorder(node*root) {
	if (!root) {
		return;
	}
	inorder(root->lchild);
	cout << root->data << " ";
	inorder(root->rchild);
	return;
}

void postorder(node*root) {
	if (!root)return;
	postorder(root->lchild);
	postorder(root->rchild);
	cout << root->data << " ";
	return;

}

int height(node*root) {
	if (!root)return 0;
	return max(height(root->lchild), height(root->rchild)) + 1;
}

//level order using queue BREADTH FIRST SEARCH(BFS)(O(N))
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

//level order 2(O(N^2))
void printKthLevel(node*root, int k) {
	if (!root)return;
	if (k == 1) {
		cout << root->data << " ";
		return;
	}
	printKthLevel(root->lchild, k - 1);
	printKthLevel(root->rchild, k - 1);
	return;
}

void levelOrder2(node*root) {
	int h = height(root);
	for (int i = 1; i <= h; ++i) {
		printKthLevel(root, i);
		cout << endll;
	}
}

int numberOfNodes(node*root) {
	if (!root)return 0;
	int l = numberOfNodes(root->lchild);
	int r = numberOfNodes(root->rchild);
	return l + r + 1;
}

int sumOfNodes(node*root) {
	if (!root)return 0;
	int l = sumOfNodes(root->lchild);
	int r = sumOfNodes(root->rchild);
	return l + r + root->data;
}

//O(n^)
int diameter(node*root) {
	if (!root)return 0;
	int d1 = height(root->lchild) + height(root->rchild);
	int d2 = diameter(root->lchild);
	int d3 = diameter(root->rchild);
	return max(d1, max(d2, d3));
}

//O(n)
pair<int, int> diameter2(node*root) {
	if (!root) {
		pair<int, int> p({0, 0});
		return p;
	}
	pair<int, int> p, l, r;
	l = diameter2(root->lchild);
	r = diameter2(root->rchild);
	p.first = max(l.first, r.first) + 1;
	p.second = max((l.first + r.first), max(l.second, r.second));
	return p;
}

int replaceBySumOfChildNodes(node*&root) {
	if (!root)return 0;
	if (!root->lchild and !root->rchild)return root->data;
	int data = root->data;
	int l = replaceBySumOfChildNodes(root->lchild);
	int r = replaceBySumOfChildNodes(root->rchild);
	root->data = l + r;
	return l + r + data;
}

//O(n) if the height() is used then the complexity becomes O(n^2)
int checkHBTree(node*root) {
	if (!root)return 0;
	int l = checkHBTree(root->lchild);
	int r = checkHBTree(root->rchild);
	if (l == -1 or r == -1)return -1;
	int h = max(l, r) + 1;
	if (abs(l - r) > 1)return -1;
	return h;
}

node* makeHBTree(int arr[], int s, int e) {
	if (s > e)return nullptr;
	int mid = (s + e) / 2;
	node*root = new node(arr[mid]);
	root->lchild = makeHBTree(arr, s, mid - 1);
	root->rchild = makeHBTree(arr, mid + 1, e);
	return root;
}

node* makeBTWithInPre(int in[], int pre[], int s, int e) {
	static int idx = 0;
	if (s > e)return nullptr;
	node *root = new node(pre[idx]);
	int index = -1;
	for (int i = s; i <= e; ++i)
	{
		if (in[i] == pre[idx]) {
			index = i;
			break;
		}
	}
	idx++;
	root->lchild = makeBTWithInPre(in, pre, s, index - 1);
	root->rchild = makeBTWithInPre(in, pre, index + 1, e);
	return root;
}

//using bfs
queue<node*> q1;
void rightView(node*root) {
	if (!root)return;
	q1.push(root);
	q1.push(nullptr);
	while (!q1.empty()) {
		node*temp = q1.front();
		q1.pop();
		bool flag = false;
		if (q1.front() == nullptr) {
			cout << temp->data << " ";
			q1.pop();
			flag = true;
		}
		if (temp->lchild) {
			q1.push(temp->lchild);
		}
		if (temp->rchild) {
			q1.push(temp->rchild);
		}
		if (flag and !q1.empty())q1.push(nullptr);
	}
	return;
}

//using bfs
queue<node*> q2;
void leftview(node*root) {
	if (!root)return;
	q2.push(nullptr);
	q2.push(root);
	while (!q2.empty()) {
		node*temp = q2.front();
		q2.pop();
		if (temp == nullptr and q2.empty()) {
			break;
		}
		if (temp == nullptr and !q2.empty()) {
			cout << q2.front()->data << " ";
			temp = q2.front();
			q2.pop();
			q2.push(nullptr);
		}
		if (temp->lchild) {
			q2.push(temp->lchild);
		}
		if (temp->rchild) {
			q2.push(temp->rchild);
		}
	}
	return;
}

//using dfs
void rightViewdfs(node*root, int level) {
	static int maxlevel = -1;
	if (!root)return;
	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	rightViewdfs(root->rchild, level + 1);
	rightViewdfs(root->lchild, level + 1);
	return;
}

//using dfs
void leftviewdfs(node*root, int level) {
	static int maxlevel = -1;
	if (!root)return;
	if (maxlevel < level) {
		cout << root->data << " ";
		maxlevel = level;
	}
	leftviewdfs(root->lchild, level + 1);
	leftviewdfs(root->rchild, level + 1);
	return;
}

int printAllNodesAtDistK(node*root, node*target, int k) {
	if (!root)return -1;
	if (root == target) {
		printKthLevel(root, k + 1);
		return 0;
	}
	int dl = -1, dr = -1;
	dl = printAllNodesAtDistK(root->lchild, target, k);
	if (dl == -1) {
		dr = printAllNodesAtDistK(root->rchild, target, k);
	}
	int d = max(dl, dr);
	if (k == d + 1) {
		cout << root->data << " ";
		return d + 1;
	}
	if (dl == -1) {
		printKthLevel(root->lchild, k - d - 1);
		return d + 1;
	} else {
		printKthLevel(root->rchild, k - d - 1);
		return d + 1;
	}
	return -1;
}

//assumption that both a and b are present in the tree and all the keys are unique
node* findLCA(node*root, int a, int b) {
	if (!root)return nullptr;
	if (root->data == a or root->data == b) {
		return root;
	}
	node*l = findLCA(root->lchild, a, b);
	node*r = findLCA(root->rchild, a, b);
	if (l and r) {
		return root;
	}
	if (!l)return r;
	return l;
}

class mypair {
public:
	int bsum;
	int msum;
	mypair() {
		bsum = msum = 0;
	}
	mypair(int a, int b) {
		bsum = a;
		msum = b;
	}
};

mypair maxSumPath(node*root) {
	if (!root) {
		mypair p;
		return p;
	}
	mypair p;
	mypair l = maxSumPath(root->lchild);
	mypair r = maxSumPath(root->rchild);
	//finding the maximum sum through a subtree using root
	int op1 = root->data;
	int op2 = l.bsum + root->data;
	int op3 = r.bsum + root->data;
	int op4 = l.bsum + r.bsum + root->data;

	int sumUsingRoot = max(op1, max(op2, max(op3, op4)));

	p.bsum = max(l.bsum, max(r.bsum, 0)) + root->data;
	p.msum = max(l.msum, max(r.msum, sumUsingRoot));
	return p;
}

int search(node*root, int key, int level) {
	if (!root)return -1;
	if (root->data == key) {
		return level;
	}
	int l = search(root->lchild, key, level + 1);
	if (l != -1) {
		return l;
	}
	return search(root->rchild, key, level + 1);
}


int minDistBtwTwoNodes(node*root, int a, int b) {
	node* lca = findLCA(root, a, b);
	int node1 = search(lca, a, 0);
	int node2 = search(lca, b, 0);
	return node1 + node2;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	node*root = buildTree();
	levelOrder2(root);
	cout << endll;
	// node*target = root->lchild->lchild;
	// int k = 3;
	// printAllNodesAtDistK(root, target, k);
	// cout << findLCA(root, 4, 11)->data << endll;
	// cout << maxSumPath(root).msum << endll;
	cout << minDistBtwTwoNodes(root, 11, 3) << endll;
	return 0;
}











//10 2 20 -1 -1 1 -1 -1 10 -1 -25 3 -1 -1 4 -1 -1
//1 2 4 6 -1 -1 7 10 -1 -1 11 -1 -1 5 8 -1 -1 9 -1 -1 3 -1 -1
//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1


/*
node* root = buildTree();
	// preorder(root);
	// cout << endll;
	// inorder(root);
	// cout << endll;
	// postorder(root);
	// cout << endll;
	// cout << "Height is " << height(root) << endll;
	// levelOrder(root);
	// cout << endll;
	levelOrder2(root);
	cout << endll;
	// cout << "No of nodes " << numberOfNodes(root) << endll;
	// cout << "Sum of nodes " << sumOfNodes(root) << endll;
	// cout << "Diameter of tree is " << diameter(root) << endll;
	// cout << "Diameter of tree is " << diameter2(root).second << endll;
	// replaceBySumOfChildNodes(root);
	// levelOrder2(root);
	// cout << endll;
	// if (checkHBTree(root) == -1) {
	// 	cout << "Not a HB tree" << endll;
	// } else {
	// 	cout << "HB Tree" << endll;
	// }
	// int arr[] {1, 2, 3, 4, 5, 6, 7};
	// int n = sizeof(arr) / sizeof(int);
	// node*HBTree;
	// HBTree = makeHBTree(arr, 0, n - 1);
	// levelOrder2(HBTree);
	// cout << endll;
	// int pre[] {1, 2, 3, 4, 8, 5, 6, 7};
	// int post[] {3, 8, 4, 2, 7, 6, 5, 1};
	// int in[] {3, 2, 8, 4, 1, 6, 7, 5};
	// int n = sizeof(in) / sizeof(int);
	// node* bt = makeBTWithInPre(in, pre, 0, n - 1);
	// levelOrder2(bt);
	// cout << endll;

	rightView(root);
	cout << endll;
	leftview(root);
	cout << endll;
	rightViewdfs(root, 0);
	cout << endll;
	leftviewdfs(root, 0);

	*/