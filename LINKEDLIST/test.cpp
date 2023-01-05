/*
* @Author: Mohit Pathak
* @Date:   2021-02-18 04:43:17
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-18 23:29:26
*/

#include<iostream>

using namespace std;

class node {
public:
	char a;
	char b;
};



int main() {
	// node * p = new node;
	// p->data = 99;
	// // p->next = nullptr;
	// // if (!p->next) {
	// // cout << p->data << endl;
	// // }

	// int * a;
	// int b;
	// a = new int;
	// cout << "=============================" << endl;
	// cout << sizeof(a) << endl;
	// cout << sizeof(*a) << endl;
	// cout << sizeof(b) << endl;

	cout << "==================================" << endl;

	cout << sizeof(node) << endl;
	//why this is 16, Shouldn't it be 12 (4 for int + 8 for node *)
	cout << sizeof(node*) << endl;

	cout << "==============================" << endl;


	// cout << sizeof(p) << endl;
	// cout << sizeof(*p) << endl;
	// cout << sizeof(p->data) << endl;
	// // cout << sizeof(p->next) << endl;
	// delete p;


	// cout << "==================================" << endl;
	// cout << sizeof(p) << endl;
	// cout << sizeof(*p) << endl;
	// cout << sizeof(p->data) << endl;
	// cout << sizeof(p->next) << endl;
	return 0;
}