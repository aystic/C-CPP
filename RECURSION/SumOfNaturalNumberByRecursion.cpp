/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 16:05:37
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-02 16:18:51
*/

#include<iostream>

using namespace std;

int sumNaturalNo(int n) {
	if (n == 0) {
		return 0;
	} else {
		return sumNaturalNo(n - 1) + n;
	}
}


int main() {
	int n;
	cin >> n;
	cout << sumNaturalNo(n) << endl;
	return 0;
}