/*
* @Author: Mohit Pathak
* @Date:   2021-02-03 16:33:52
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 16:52:00
*/

#include<iostream>

using namespace std;

int arr[3];
int factorial(int n, int r) {
	static int x = n;
	if (n == 0)
		return 1;
	else {
		int test = n * factorial(n - 1, r);
		if (n == r) {
			arr[1] = test;
		}
		if (n == x - r) {
			arr[2] = test;
		}
		arr[0] = test;
		return test;
	}
}

int PascalsCombination(int n, int r) {
	if (r == n || r == 0)
		return 1;
	else
		return PascalsCombination(n - 1, r) + PascalsCombination(n - 1, r - 1);
}

int combination(int n, int r) {
	if (r == n || r == 0)
		return 1;
	factorial(n, r);
	return arr[0] / (arr[1] * arr[2]);
}

int main() {
	int n, r;
	cin >> n >> r;
	cout << combination(n, r) << endl;
	cout << PascalsCombination(n, r) << endl;
	return 0;
}