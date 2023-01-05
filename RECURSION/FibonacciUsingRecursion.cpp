/*
* @Author: Mohit Pathak
* @Date:   2021-02-03 13:50:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-05 20:50:04
*/

#include<iostream>

using namespace std;

//O(2^n) solution

// int fibonacci(int n){
// 	if(n<=2)
// 		return n;
// 	else{
// 		return fibonacci(n-2)+fibonacci(n-1);
// 	}
// }

int fibonacci(int n) {
	static int test = 0;
	if (n <= 2)
		return n;
	else {
		return fibonacci(n - 2) + fibonacci(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cout << fibonacci(i) << " ";
	}
	fibonacci(n);
	return 0;
}