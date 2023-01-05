/*
* @Author: Mohit Pathak
* @Date:   2021-05-29 16:28:22
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 16:44:53
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

class dummy {
	int a;
	int *ptr;
	int *arr;
public:
	dummy() {}
	dummy(int a) {
		this->a = a;
		ptr = &(this->a);
		arr = new int[5];
		for (int i = 0; i < 5; ++i)
		{
			arr[i] = i + 1;
		}
	}
	~dummy() {
		delete[] arr;
	}

	void deepcopy(const dummy & temp) {
		a = temp.a;
		ptr = &a;
		arr = new int[5];
		for (int i = 0; i < 5; ++i)
		{
			arr[i] = temp.arr[i];
		}
	}

	void operator=(const dummy & temp) {
		//delete the previour object;
		ptr = nullptr;
		delete[] arr;
		deepcopy(temp);
	}

	void display() {
		cout << a << endll;
		cout << *ptr << endll;
		for (int i = 0; i < 5; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endll;
	}
	void displayAdd() {
		cout << &a << endll;
		cout << ptr << endll;
		cout << arr << endll;
	}
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	dummy d{5};
	d.displayAdd();
	dummy e{d};
	e.displayAdd();
	dummy f;
	f = d;
	f.displayAdd();
	dummy g;
	g.deepcopy(d);
	g.displayAdd();
	return 0;
}