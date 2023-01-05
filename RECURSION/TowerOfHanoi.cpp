/*
* @Author: Mohit Pathak
* @Date:   2021-02-03 17:29:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 17:32:56
*/

#include<iostream>

using namespace std;

int steps;
void TOH(int n, int a, int b, int c) {
	if (n == 1) {
		cout << "Move one disc from " << a << " to " << c << endl;
		steps++;
		return;
	} else {
		TOH(n - 1, a, c, b);
		TOH(1, a, b, c);
		TOH(n - 1, b, a, c);
	}
}


int main() {
	int n;
	cin >> n;
	int a = 1, b = 2, c = 3;
	TOH(n, a, b, c);
	cout << steps << endl;
	return 0;
}