/*
* @Author: Mohit Pathak
* @Date:   2021-02-09 13:13:47
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-09 13:36:12
*/

#include<iostream>
using namespace std;

template <class t>
class array {
private:
	t *arr;
	int size;
	int length;
public:
	array() {
		size = 10;
		length = 0;
		arr = new t[size];
	}
	array(int sz) {
		size = sz;
		length = 0;
		arr = new t [size];
	}
	~array() {
		delete [] arr;
	}
	void display();
	void insert (t x, int idx);
	t deleteAnElement(int idx);
};

template <class t>
void array<t>::display() {
	for (int i = 0; i < length; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template <class t>
void array<t>::insert(t x, int idx) {
	if (idx < 0 || idx > length) {
		cout << "Invalid Index!!";
	} else {
		for (int i = length; i > idx; --i)
		{
			arr[i] = arr[i - 1];
		}
		arr[idx] = x;
		length++;
	}
	cout << "Insert Successfull!" << endl;
	display();
}

template <class t>
t array<t>::deleteAnElement(int idx) {
	if (idx < 0 || idx > length)
		cout << "Invalid Index!" << endl;
	t x = arr[idx];
	for (int i = idx; i < length - 1; ++i)
	{
		arr[i] = arr[i + 1];
	}
	length--;
	return x;
}

int main() {
	array <char> a{5};
	a.display();
	a.insert(65, 0);
	a.insert(66, 1);
	a.insert(67, 2);
	a.insert(68, 3);
	a.insert(69, 4);
	a.display();
	cout << a.deleteAnElement(1) << endl;
	a.display();
	return 0;
}