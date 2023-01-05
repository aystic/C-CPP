/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 01:52:26
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-12 01:55:12
*/

#include<iostream>

using namespace std;

int main() {
	int a, b;
	cout << "a and b" << endl;
	cin >> a >> b;
	b = b - a;
	a = a + b;
	b = a - b;
	cout << "a => " << a << endl;
	cout << "b => " << b << endl;
	return 0;
}