/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 18:52:33
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 18:59:09
*/

#include<iostream>

using namespace std;

void Recursion(int n) {
	if (n >= 0) {
		cout << n << " "; //Descending Printing and calling phase
		Recursion(n - 1);
		if (n == 0) {
			cout << endl;
		}
		cout << n << " "; //Ascending Printing and Returning phase
	}
}


int main() {
	int n = 10;
	Recursion(n);
	return 0;
}
