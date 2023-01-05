/*
* @Author: Mohit Pathak
* @Date:   2021-06-12 01:36:30
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-12 02:26:28
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	string s0;//NULL STRING
	string s1 = "hello";
	string s2 {"hello world"};
	string s3(s2);//COPY CONSTRUCTOR
	string s4 = s2;
	char arr[] {"hello there how you doing?"};
	string s5{arr};

	//OUTPUT
	// cout << s0 << endl;
	// cout << s1 << endl;
	// cout << s2 << endl;
	// cout << s3 << endl;
	// cout << s4 << endl;
	// cout << s5 << endl;

	// if (s0.empty()) {
	// 	cout << "the s0 string is empty" << endl;
	// }
	// cout << "the length of the string s0 is " << s0.length() << endl;
	// cout << "The length of the string s5 is " << s5.length() << endl;
	// s0.append(s5);
	// s5.clear();
	// cout << "The length of the string s5 is " << s5.length() << endl;
	// cout << "the length of the string s0 is " << s0.length() << endl;
	// cout << s0 << endl;
	// s0 += "\nI am doing good";
	// cout << s0 << endl;

	// s1 = "apple";
	// s2 = "Mango";
	// cout << s2.compare(s1) << endl;
	// cout << "the length of the string s0 is " << s0.length() << endl;
	// cout << s1 + s2 << endl;
	// if (s1 > s2) {
	// 	cout << "s1 is greater" << endl;
	// } else {
	// 	cout << "s2 is greater" << endl;
	// }
	int index = s5.find("you");
	cout << index << endl;
	s5.erase(16, 4);
	cout << s5 << endl;
	return 0;
}