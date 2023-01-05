/*
* @Author: pmohit
* @Date:   2021-02-03 22:44:09
* @Last Modified by:   pmohit
* @Last Modified time: 2021-02-03 22:44:09
*/

#include<iostream>

using namespace std;




int main() {
	int arr[10] = {0};
	for (int i = 0; i < 10; i++) {
		arr[i] = ++i;
	}
	cout << arr[5] << " " << 5[arr] << " " << *(arr + 5) << endl;
	return 0;
}