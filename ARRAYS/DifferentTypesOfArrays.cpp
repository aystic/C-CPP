/*
* @Author: Mohit Pathak
* @Date:   2021-02-14 02:04:41
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-14 03:41:20
*/

#include<iostream>

using namespace std;

/*
i and j values are taken according to maths
starting from 1
*/


class diagonalArray {
	int *a;
	int n;
public:
	diagonalArray(int n) {
		this->n = n;
		a = new int[n];
	}
	~diagonalArray() {
		delete []a;
	}
	void set( int i, int j, int x);
	int get( int i, int j);
	void display();
};
void diagonalArray::set(int i, int j, int x) {
	if (i == j)
		a[i - 1] = x;
}
int diagonalArray::get(int i, int j) {
	if (i != j)
		return 0;
	else
		return a[i - 1];
}
void diagonalArray::display() {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i != j)
				cout << "0" << " ";
			else
				cout << a[i] << " ";
		}
		cout << endl;
	}
}



class lowertriangular {
	int *a;
	int n;
public:
	lowertriangular(int n) {
		this->n = n;
		a = new int[n * (n + 1) / 2];
	}
	~lowertriangular() {
		delete []a;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};
void lowertriangular::set(int i, int j, int x) {
	if (i >= j) {
		int idx = i * (i - 1) / 2 + j - 1;
		a[idx] = x;
	}
}
int lowertriangular::get(int i, int j) {
	if (i < j)
		return 0;
	else
		return a[i * (i - 1) / 2 + j - 1];
}
void lowertriangular::display() {
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i < j)
				cout << "0" << " ";
			else {
				cout << a[(i - 1) *i / 2 + j - 1] << " ";
			}
		}
		cout << endl;
	}
}



class uppertriangular {
	int *a;
	int n;
public:
	uppertriangular(int n) {
		this->n = n;
		a = new int[n * (n + 1) / 2];
	}
	~uppertriangular() {
		delete []a;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};
void uppertriangular::set(int i, int j, int x) {
	if (i <= j) {
		int idx = j * (j - 1) / 2 + i - 1;
		a[idx] = x;
	}
}
int uppertriangular::get(int i, int j) {
	if (i > j)
		return 0;
	else
		return a[j * (j - 1) / 2 + i - 1];
}
void uppertriangular::display() {
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i > j)
				cout << "0" << " ";
			else {
				cout << a[(j - 1) *j / 2 + i - 1] << " ";
			}
		}
		cout << endl;
	}
}


class symmetric {
	int *a;
	int n;
public:
	symmetric(int n) {
		this->n = n;
		a = new int[n * (n + 1) / 2];
	}
	~symmetric() {
		delete []a;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};
void symmetric::set(int i, int j, int x) {
	if (i >= j) {
		int idx = i * (i - 1) / 2 + j - 1;
		a[idx] = x;
	}
}
int symmetric::get(int i, int j) {
	if (i < j)
		return a[j * (j - 1) / 2 + i - 1];
	else
		return a[i * (i - 1) / 2 + j - 1];
}
void symmetric::display() {
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i < j)
				cout << a[j * (j - 1) / 2 + i - 1] << " ";
			else {
				cout << a[(i - 1) *i / 2 + j - 1] << " ";
			}
		}
		cout << endl;
	}
}


class tridiagonal {
	int n;
	int *a;
public:
	tridiagonal(int n) {
		this->n = n;
		a = new int[3 * n - 2 ];
	}
	~tridiagonal() {
		delete []a;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};
void tridiagonal::set(int i, int j, int x) {
	if (i > j) {
		a[2 * n - 1 + j - j - 2] = x;
	} else if (i < j) {
		a[i - 1] = x;
	} else {
		a[n - 1 + i - 1] = x;
	}
}
int tridiagonal::get(int i, int j) {
	if (i > j) {
		return a[2 * n - 1 + j - j - 2];
	} else if (i < j) {
		return a[i - 1];
	} else {
		return a[n - 1 + i - 1];
	}
}
void tridiagonal::display() {
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (abs(i - j) <= 1) {
				if (i > j) {
					cout << a[2 * n - 1 + j - j - 2] << " ";
				} else if (i < j) {
					cout << a[i - 1] << " ";
				} else {
					cout << a[n - 1 + i - 1] << " ";
				}
			} else {
				cout << "0" << " ";
			}

		}
		cout << endl;
	}
}


class toeplitz {
	int *a;
	int n;
public:
	toeplitz(int n) {
		this->n = n;
		a = new int[2 * n - 1];
	}
	~toeplitz() {
		delete []a;
	}
	void set(int i, int j, int x);
	int get(int i, int j);
	void display();
};
void toeplitz::set(int i, int j, int x) {
	if (i == 1) {
		a[j - 1] = x;
	} else if (j == 1) {
		a[n + i - 2] = x;
	}
}
int toeplitz::get(int i, int j) {
	if (i <= j) {
		return a[j - i];
	} else {
		return a[n + i - j - 1];
	}
}
void toeplitz::display() {
	for (int i = 1	; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i <= j) {
				cout << a[j - i] << " ";
			} else {
				cout << a[n + i - j - 1] << " ";
			}
		}
		cout << endl;
	}
}


int main() {
	// diagonalArray arr{5};
	// arr.set(1, 1, 11);
	// arr.set(2, 2, 22);
	// arr.set(3, 3, 33);
	// arr.set(4, 4, 44);
	// arr.set(5, 5, 55);
	// cout << arr.get(3, 3) << endl;
	// arr.display();

	// uppertriangular arr{3};
	// arr.set(1, 1, 11);
	// arr.set(1, 2, 12);
	// arr.set(1, 3, 13);
	// arr.set(2, 2, 22);
	// arr.set(2, 3, 23);
	// arr.set(3, 3, 33);
	// cout << arr.get(3, 3) << endl;
	// arr.display();

	// symmetric arr{3};
	// arr.set(1, 1, 11);
	// arr.set(2, 1, 21);
	// arr.set(2, 2, 22);
	// arr.set(3, 1, 31);
	// arr.set(3, 2, 32);
	// arr.set(3, 3, 33);
	// cout << arr.get(3, 3) << endl;
	// arr.display();

	// tridiagonal arr{3};
	// arr.set(1, 1, 11);
	// arr.set(1, 2, 12);
	// arr.set(2, 1, 21);
	// arr.set(2, 2, 22);
	// arr.set(2, 3, 23);
	// arr.set(3, 2, 32);
	// arr.set(3, 3, 33);
	// cout << arr.get(3, 3) << endl;
	// arr.display();

	// toeplitz arr{4};
	// arr.set(1, 1, 1);
	// arr.set(1, 2, 2);
	// arr.set(1, 3, 3);
	// arr.set(1, 4, 4);
	// arr.set(2, 1, 5);
	// arr.set(3, 1, 6);
	// arr.set(4, 1, 7);
	// cout << arr.get(3, 3) << endl;
	// arr.display();

	return 0;
}