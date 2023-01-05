/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 00:56:36
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-12 01:16:17
*/

#include<iostream>

using namespace std;

int main() {
	char a[100];
	char enter = 10;
	cin >> a;
	for (int i = 0; a[i] != '\0'; ++i)
	{
		if (a[i] <= 90) {
			a[i] += 32;
		} else {
			a[i] -= 32;
		}
	}
	cout << a << endl;
	return 0;
}