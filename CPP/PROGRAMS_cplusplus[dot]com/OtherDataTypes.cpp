/*
* @Author: Mohit Pathak
* @Date:   2021-05-28 13:14:23
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-05-29 06:35:54
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

using i = int;
typedef long long ll;

union test {
	int a;
	float f;
	double d;
	char c;
} u;

enum colours {
	yellow = 25,
	blue,
	black,
	green,
	grey
};

enum class colors : char {
	yellow,
	blue,
	black,
	green,
	grey
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	ll a = 35;
	i b = 99;
	cout << a << " " << b << endll;
	cout << sizeof(u) << endll;
	colours c;
	c = yellow;
	cout << c << endll;
	colors co;
	co = colors::yellow;
	return 0;
}