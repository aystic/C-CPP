/*
* @Author: Mohit Pathak
* @Date:   2021-03-05 13:59:31
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-03-05 14:17:02
*/

#include<iostream>

using namespace std;

void heapify(int *arr, int n) {
	for (int i = n - 1; i >= 0; --i)
	{
		int j = i;
		int temp = arr[j];
		while (j < n && (2 * j + 1 < n || 2 * j + 2 < n)) {
			int left = 2 * j + 1;
			int right = 2 * j + 2;
			if (right < n) {
				if (arr[left] >= arr[right] && temp < arr[left]) {
					arr[j] = arr[left];
					j = left;
				} else if (arr[left] < arr[right] && temp < arr[right]) {
					arr[j] = arr[right];
					j = right;
				}
			} else if (left < n) {
				if (arr[left] > temp) {
					arr[j] = arr[left];
					j = left;
				}
			}
			arr[j] = temp;
		}
	}
}

int main() {
	int arr[] {10, 1, 2, 45, 33, 2, 8, 6, 11, 13, -5};
	heapify(arr, 11);
	for (int i = 0; i < 11; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}