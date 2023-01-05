/*
* @Author: Mohit Pathak
* @Date:   2021-02-12 00:25:52
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-12 02:07:57
*/

#include<iostream>

using namespace std;

int main() {
	//Methods of initialization
	char a = 'A';
	char b = 65;
	cout << a << " " << b << endl;//output : A A
	//Operations on characters : Incrementing and decrementing
	a++;
	b++;
	b++;
	cout << a << " " << b << endl; //Output : B C
	if (b > a)//b greater than a : Comparison of two characters
		cout << "b Greater than a" << endl;
	if (a == 66)//comparison with int
		cout << "a is 66" << endl;
	cout << (int)a << " " << (int)b << endl; //Output : 66 67
	return 0;
}