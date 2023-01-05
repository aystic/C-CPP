/*
* @Author: Mohit Pathak
* @Date:   2021-02-10 01:09:26
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-10 20:01:34
*/

#include<iostream>
#include<algorithm>
using namespace std;

bool issorted(int a[], int n) {
	for (int i = 0; i < n - 1; ++i)
	{
		if (a[i] > a[i + 1])
			return false;
	}
	return true;
}

void NormalApproach(int a[], int n, int sum) {
	for (int i = 0; i < n - 1; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (a[i] + a[j] == sum)
				cout << "Pair " << a[i] << " " << a[j] << endl;
		}
	}
}

void UsingHashTable(int a[], int n, int sum) {
	int max = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];
	}
	int c[max + 1] {0};
	for (int i = 0; i < n; ++i)
	{
		c[a[i]] = 1;
		if (a[i] < sum) {
			if (c[sum - a[i]] == 1 && sum - a[i] != a[i])
				cout << "Pair " << a[i] << " " << sum - a[i] << endl;
		}

	}
}

void UsingTwoPointerApproach(int a[], int n, int sum) //Sorted array required
{
	int i = 0, j = n - 1;
	if (!issorted(a, n)) {
		sort(a, a + n);
	}
	while (i < j) {
		if (a[i] + a[j] < sum)
			i++;
		else if (a[i] + a[j] > sum)
			j--;
		else {
			cout << "Pair is " << a[i] << " " << a[j] << endl;
			i++;
			j--;
		}
	}
}


int main() {
	int sum;
	cin >> sum;
	int a[] {1, 5, 2, 3, 7, 9, 12, 10, 11, 6, 4};
	UsingHashTable(a, 11, sum);
	cout << endl;
	NormalApproach(a, 11, sum);
	cout << endl;
	UsingTwoPointerApproach(a, 11, sum);
	return 0;
}