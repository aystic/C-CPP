/*
* @Author: Mohit Pathak
* @Date:   2021-02-06 17:23:28
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-06 17:30:42
*/

#include<iostream>

using namespace std;

class array {
public:
	int *arr;
	int size;
	int length;
};

void merge(array a, array b) {
	int arr[12];
	int i = 0, j = 0, k = 0;
	while (i < 5 && j < 7) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}
	while (i < 5) {
		c[k++] = a[i++];
	}
	while (j < 7) {
		c[k++] = b[j++];
	}
	for (int i = 0; i < 12; ++i)
	{
		cout << c[i] << " ";
	}
	cout << endl;
}

int main() {
	array *a, *b;
	a = new array;
	b = new array;
	a->arr = new int[5];
	b->arr = new int[7];
	merge(*a, *b);

	return 0;
}