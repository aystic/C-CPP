#include<iostream>
using namespace std;

void InsertionSort(int a[], int n) {
	int start = 1;
	int counter;
	int temp;
	for (start = 1; start < n; start++) {
		counter = start - 1;
		temp = a[start];
		while (counter >= 0) {
			if (a[counter] > temp) {
				a[counter + 1] = a[counter];
			}
			else {
				a[counter + 1] = temp;
				break;
			}
			counter--;
		}
		if (counter == -1)
			a[0] = temp;
	}


}

void display(int arr[], int n) {
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[10];
	int count = 10;
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = count;
		count--;
	}
	display(arr, 10);
	InsertionSort(arr, 10);
	display(arr, 10);
	return 0;
}