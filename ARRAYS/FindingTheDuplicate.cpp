/*
* @Author: Mohit Pathak
* @Date:   2021-02-09 22:54:18
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-09 23:27:09
*/

#include<iostream>

using namespace std;

//=======================================
//Sorted Array

//O(n)
void findDuplicates(int a[], int n) {
	int lastDuplicate = -1;
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] == a[i + 1] && a[i + 1] != lastDuplicate) {
			cout << a[i] << endl;
			lastDuplicate = a[i];
		}
	}
}

//O(n)
void countingDuplcates(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] == a[i + 1]) {
			int j = i + 1;
			while (a[j] == a[i]) {
				j++;
			}
			cout << "Duplicate Element is " << a[i] << " and its count is " << j - i << endl;
			i = j - 1;
		}

	}
}


//O(n)
void countingDuplcatesUsingHashTable(int a[], int n) {
	int min = a[0], max = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] < min)
			min = a[i];
		if (a[i] > max)
			max = a[i];
	}
	int c[max + 1] {0};
	for (int i = 0; i < n; ++i)
	{
		c[a[i]]++;
	}
	for (int i = min + 1 ; i < max + 1; ++i)
	{
		if (c[i] > 1)
			cout << "Duplicate Element is " << i << " and the count is " << c[i] << endl;
	}
}
//===============================

//===============================
//Unsorted Array O(n^2)
void DuplicateUnsorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		int count = 1;
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] == a[j] && a[i] != -1) {
				count++;
				a[j] = -1;
			}
		}
		if (count != 1)
			cout << "Duplicate Element is " << a[i] << " and its count is " << count << endl;
	}
}


//===============================

int main() {
	int a[] {1, 2, 3, 4, 4, 5, 6, 6, 6, 6, 7, 8, 8, 9, 11};
	findDuplicates(a, 15);
	cout << endl;
	countingDuplcates(a, 15);
	cout << endl;
	countingDuplcatesUsingHashTable(a, 15);
	cout << endl;
	DuplicateUnsorted(a, 15);
	return 0;
}