/*
* @Author: Mohit Pathak
* @Date:   2021-02-09 14:18:40
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-09 22:54:03
*/

#include<iostream>

using namespace std;

int MissingInSortedArray(int a[], int an) {
	int sumExpected = (an + 1) * (an + 2) / 2;
	int sumActual = 0;
	for (int i = 0; i < an; ++i)
	{
		sumActual += a[i];
	}
	return sumExpected - sumActual;
}

void MissingInSortedSequence(int b[], int bn) {
	int difference = b[0];
	for (int i = 0; i < bn; ++i)
	{
		if (b[i] - i != difference) {
			int numberOfElements = b[i] - i - difference;
			for (int j = 0; j < numberOfElements; ++j)
			{
				cout << "The missing element is " << i + difference + j << endl;
			}
			difference = b[i] - i;
		}
	}
}

void MissingInUnsortedArray(int a[], int an) {
	int max = a[0], min = a[0];
	for (int i = 0; i < an; ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int size = max + 1;
	int c[size] {0};
	for (int i = 0; i < an; ++i)
	{
		c[a[i]									] = 1;
	}
	for (int i = min + 1; i < size; ++i)
	{
		if (c[i] == 0)
			cout << "Missing element is " << i << endl;
	}

}

int main() {
	int a[] {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};//Missing element is 7
	int b[] {6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 19};//Missing elements are 13, 17 and 18
	int c[] {11, 6, 9, 8, 7, 12, 14, 10, 16, 19, 15}; //Missing elements are 13, 17 and 18
	cout << MissingInSortedArray(a, 11) << endl;//sorted array required
	MissingInSortedSequence(b, 11); //sorted array required
	MissingInUnsortedArray(c, 11);//unsorted array-
	return 0;
}