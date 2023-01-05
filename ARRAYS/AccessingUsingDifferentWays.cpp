/*
* @Author: Mohit Pathak
* @Date:   2021-02-11 23:48:41
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-11 23:57:07
*/

#include<iostream>

using namespace std;




int main() {
	int a[3][4];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			a[i][j] = 10 * i + j;
		}
	}

	//using the subscripted notation
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	cout << "==========================================" << endl;
	//using the int* pointer approach
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << *(&a[0][0] + i * 4 + j) << " " ;
		}
		cout << endl;
	}

	cout << "============================================" << endl;
	//using the pointer and subscript approach
	int*m = &a[0][0];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << m[i * 4 + j] << " ";
		}
		cout << endl;
	}
	cout << "===============================================" << endl;
	//using the int(*)[][] approach
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			cout << *(*(*(&a) + i) + j) << " ";
		}
		cout << endl;
	}
	return 0;
}