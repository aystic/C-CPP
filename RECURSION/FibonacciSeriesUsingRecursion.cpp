/*
* @Author: Mohit Pathak
* @Date:   2021-02-03 14:16:05
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 15:39:23
*/

#include<iostream>

using namespace std;

void FibonacciUsingLoops(int n) {
	int t1 = 0, t2 = 1;
	int s = 0;
	if (n <= 2) {
		cout << t1 << " ";
		if (n == 2)
			cout << t2 << " ";
	}
	else {
		cout << t1 << " " << t2 << " ";
		for (int i = 3; i <= n; i++) {
			s = t1 + t2;
			t1 = t2;
			t2 = s;
			cout << s << " ";
		}
	}
	cout << endl;
}

int FibonacciUsingRecursion(int n) {
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return FibonacciUsingRecursion(n - 2) + FibonacciUsingRecursion(n - 1);
}
void printfibonacci(int n) {
	for (int i = 1; i <= n; i++) {
		cout << FibonacciUsingRecursion(i) << " ";
	}
	cout << endl;
}


int fibOptimized(int n) {
	static int arr[100] {0};
	if (n <= 1) {
		if (arr[n] == 0) {
			arr[n] = n;
		}
		return arr[n];
	} else {
		if (arr[n - 1] == 0) {
			arr[n - 1] = fibOptimized(n - 1);
			if (arr[n - 2] == 0)
				arr[n - 2] = fibOptimized(n - 2);
		}
		return arr[n - 1] + arr[n - 2];
	}
}
// void PrintfibOptimized(int n) {
// 	for (int i = 0; i < n; ++i)
// 	{
// 		cout << fibOptimized(i) << " ";
// 	}
// 	cout << endl;
// }


int main() {
	int n;
	cin >> n;
	FibonacciUsingLoops(n);
	// printfibonacci(n);
	cout << fibOptimized(n - 1) << endl;
	return 0;
}