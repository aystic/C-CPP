/*
* @Author: Mohit Pathak
* @Date:   2021-02-10 20:08:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-10 20:19:30
*/

#include<iostream>

using namespace std;

void MinAndMax(int a[], int n) {
	int min = a[0], max = a[0];
	for (int i = 1; i < n; ++i)
	{
		if (a[i] < min) {
			min = a[i];
			continue;//if the number is less than min then
			// there is no need to check for the max condition
		}
		if (a[i] > max) {
			max = a[i];
		}
	}
	cout << "The Maximum is " << max << " and the Minimum is " << min << endl;
}


int main() {
	int a[] {10, 9, 3, 2, -99, 33, 99, 22, 74};
	MinAndMax(a, 9);
	return 0;
}