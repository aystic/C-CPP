/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 00:25:52
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-12 00:29:18
*/

#include<iostream>

using namespace std;

int main() {
	//Methods of initialization
	char a = 'A';
	char b = 65;
	cout << a << " " << b << endl;//output : A A
	//Operations on characters
	a++;
	b++;
	b++;
	cout << a << " " << b << endl; //Output : B C
	if (b > a)//b greater than a
		cout << "b Greater than a" << endl;
	return 0;
}