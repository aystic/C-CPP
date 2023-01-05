/*
* @Author: Mohit Pathak
* @Date:   2021-02-03 23:17:42
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-03 23:26:39
*/

#include<iostream>

using namespace std;




int main() {
	int a[10] = {0};
	int * p;
	p = new int[10];
	cout << &p << " " << p << endl;
	for (int i = 0; i < 10; ++i)
	{
		a[i] = i + 1;
		p[i] = i + 1;;
	}
	for (int i = 0; i < 10; ++i)
	{
		cout << a[i] << " " << p[i] << endl;
	}
	delete [] p;
	p = nullptr;
	cout << &p << " " << p << endl;
	return 0;
}