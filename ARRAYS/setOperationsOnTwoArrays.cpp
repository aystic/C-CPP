/*
* @Author: Mohit Pathak
* @Date:   2021-02-07 22:32:31
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-08 22:51:38
*/

// Program for performing set operations on two arrays
// union
// intersection
// difference
// set membership ==> searching


#include<iostream>
#include<algorithm>

using namespace std;

void display(int a[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

bool issorted(int a[], int an) {
	for (int i = 0; i < an - 1; ++i)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}


void unionUnsortedArrays(int a[], int an, int b[], int bn) {
	int cn = an + bn;
	int c[cn];
	int clength = 0;
	//copying any one array as it is to the third array
	for (int i = 0; i < an; ++i)
	{
		c[i] = a[i];
		clength++;
	}
	//Traversing through all the elements of the second array and checking if the third array already have
	//the same element, if no then copy the element into the third array
	for (int i = 0; i < bn; ++i)
	{
		int j = 0;
		for (; j < clength; ++j)
		{
			if (b[i] == c[j])
				break;
		}
		if (j == clength) {
			c[clength++] = b[i];
		}
	}
	display(c, clength);

}

void unionSortedArrays(int a[], int an, int b[], int bn) {
	int cn = an + bn;
	int c[cn];
	int clength = 0;
	//sorting both the source arrays if not sorted
	if (!issorted(a, an)) {
		sort(a, a + an);
	}
	if (!issorted(b, bn)) {
		sort(b, b + bn);
	}
	int i = 0, j = 0, k = 0;
	while (i < an && j < bn) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		} else if (a[i] > b[j]) {
			c[k++] = b[j++];
		} else {
			c[k++] = a[i++];
			j++;
		}
		clength++;
	}
	while (i < an) {
		c[k++] = a[i++];
		clength++;
	}
	while (j < bn) {
		c[k++] = b[j++];
		clength++;
	}
	display(c, clength);
}

void intersectionUnsortedArrays(int a[], int an, int b[], int bn) {
	int cn = an > bn ? an : bn;
	int c[cn];
	int clength = 0;
	for (int i = 0; i < an; ++i)
	{
		for (int j = 0; j < bn; ++j)
		{
			if (a[i] == b[j]) {
				c[clength] = a[i++];
				clength++;
			}
		}
	}
	display(c, clength);
}

void intersectionSortedArrays(int a[], int an, int b[], int bn) {
	//sorting both the source arrays if not sorted
	if (!issorted(a, an)) {
		sort(a, a + an);
	}
	if (!issorted(b, bn)) {
		sort(b, b + bn);
	}
	int cn = an > bn ? an : bn;
	int c[cn];
	int clength = 0;
	int i = 0, j = 0;
	while (i < an && j < bn) {
		if (a[i] == b[j]) {
			c[clength++] = a[i++];
			j++;
		} else {
			if (a[i] < b[j]) {
				i++;
			} else {
				j++;
			}
		}

	}
	display(c, clength);
}

void differenceUnsortedArrays(int a[], int an, int b[], int bn) {
	int cn = an;
	int c[cn], clength = 0;
	for (int i = 0; i < an; ++i)
	{
		int j = 0;
		for (; j < bn; ++j)
		{
			if (a[i] == b[j]) {
				break;
			}
		}
		if (j == bn) {
			c[clength++] = a[i];
		}
	}
	display(c, clength);
}

void differenceSortedArrays(int a[], int an, int b[], int bn) {
	//sorting both the source arrays if not sorted
	if (!issorted(a, an)) {
		sort(a, a + an);
	}
	if (!issorted(b, bn)) {
		sort(b, b + bn);
	}
	int cn = an;
	int c[cn];
	int clength = 0;
	int i = 0, j = 0;
	while (i < an && j < bn) {
		if (a[i] < b[j]) {
			c[clength++] = a[i++];
		} else if (a[i] > b[j]) {
			j++;
		} else {
			i++;
			j++;
		}
	}
	while (i < an) {
		c[clength++] = a[i++];
	}
	display(c, clength);
}


int main() {
	int a[] {1, 4, 2, -10, 99}, b[] {0, -2, 4, 8, 99, 123, 44};
	int an = 5, bn = 7;
	display(a, an);
	display(b, bn);
	unionUnsortedArrays(a, an, b, bn);
	unionSortedArrays(a, an, b, bn);
	intersectionUnsortedArrays(a, an, b, bn);
	intersectionSortedArrays(a, an, b, bn);
	differenceUnsortedArrays(a, an, b, bn);
	differenceUnsortedArrays(b, bn, a, an);
	differenceSortedArrays(a, an, b, bn);
	differenceSortedArrays(b, bn, a, an);
	return 0;
}