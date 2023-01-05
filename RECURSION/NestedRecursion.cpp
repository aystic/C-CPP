/*
* @Author: Mohit Pathak
* @Date:   2021-02-02 16:01:07
* @Last Modified by:   pmohit
* @Last Modified time: 2021-02-02 16:02:53
*/

#include<iostream>

using namespace std;

int func(int n) {
	if (n > 100) {
		return n - 10;
	} else {
		return func(func(n + 11));
	}
}


int main() {
	cout << func(95) << endl;
	return 0;
}