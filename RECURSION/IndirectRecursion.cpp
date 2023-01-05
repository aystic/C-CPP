/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 15:51:49
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 15:53:29
*/

#include<iostream>

using namespace std;

void func2(int);
void func1(int n) {
	if (n > 0) {
		cout << n << " ";
		func2(n - 1);
	}
}

void func2(int n) {
	if (n > 1) {
		cout << n << " ";
		func1(n / 2);
	}
}

int main() {
	func1(20);
	return 0;
}