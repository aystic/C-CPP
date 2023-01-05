/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 16:21:42
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 13:49:25
*/

#include<iostream>

using namespace std;

int recursion(int n) {
	if (n == 0)
		return 1;
	else
		return n * recursion(n - 1);
}


int main() {
	cout << recursion(5) << endl;
	return 0;
}