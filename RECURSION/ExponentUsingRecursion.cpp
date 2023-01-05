/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 16:28:49
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 16:40:59
*/

#include<iostream>

using namespace std;

int exponent(int n, int m) {
	if (m == 0)
		return 1;
	else
		return n * exponent(n, m - 1);

}

int fastexponent(int n, int m) {
	if (m % 2 == 1) {
		if (m == 1)
			return n;
		else
			return n * fastexponent(n * n, m / 2);
	} else {
		if (m == 0)
			return 1;
		else
			return n * n * fastexponent(n * n, (m - 2) / 2);
	}

}

int main() {
	cout << "Enter n and m for n^m :";
	int n, m;
	cin >> n >> m;
	cout << exponent(n, m) << endl;
	cout << fastexponent(n, m) << endl;
	return 0;
}