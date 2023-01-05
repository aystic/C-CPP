/*
* @Author: Mohit Pathak
* @Date:   2021-05-26 03:25:23
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-27 03:16:58
*/

//#include<bits/stdc++.h>
#include<iostream>

#define endll '\n'
using namespace std;
//==============================================

/*

operators
Arithmetic
Compound
Increment & Decrement
Relational & comparison{
	== > < <= >= !=
}
Logical{
	&& || !
}
Conditional Ternnary operator
Comma operator
Bitwise operator{
	& | ^ ~ << >>
}
*/


//==============================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//================================================

	int x, y, z;
	x = (y = 5) + (z = 10);//which is equivalent to x=5+10;
	cout << x << " " << y << " " << z << endll;
	x = (y = 25, y + z);
	cout << x << " " << y << " " << z << endll;

	int a;
	float f = 3.14159;
	a = int(f); //explicit typecasting or (int)f;
	cout << a << endll;
	return 0;
}