/*
* @Author: Mohit Pathak
* @Date:   2021-02-06 10:33:37
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-06 17:20:11
*/

#include<iostream>

using namespace std;




int main() {
	int a[5] {3, 5, 8, 13, 26}, b[7] {1, 2, 9, 19, 29, 39, 99};
	int c[12];
	int i = 0, j = 0, k = 0;
	while (i < 5 && j < 7) {
		if (a[i] < b[j]) {
			c[k++] = a[i++];
		} else {
			c[k++] = b[j++];
		}
	}
	if (i == 5) {
		while (j < 7)
			c[k++] = b[j++];
	} else if (j == 7) {
		while (i < 5)
			c[k++] = a[i++];
	}
	for (i = 0; i < 12; i++) {
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}