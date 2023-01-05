/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 13:00:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-28 13:01:45
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

struct rectangle
{
	int length;
	int width;
} r1;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	rectangle r2;
	r1.length = 11;
	r1.width = 99;
	cout << "Area of r1 is " << r1.length*r1.width << endll;


	return 0;
}