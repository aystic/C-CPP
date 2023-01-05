/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-07 22:52:00
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-07 23:12:18
*/
#include<iostream>
#include <string>
#include <unordered_map>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class student {
public:
	string firstName;
	string lastName;
	int rollNumber;
	student(string s1, string s2, int n) {
		firstName = s1;
		lastName = s2;
		rollNumber = n;
	}
	bool operator==(const student& s)const {
		return rollNumber == s.rollNumber;
	}
};

class hashFunction {
public:
	ll operator()(const student& s)const {
		return s.firstName.length() + s.lastName.length() + s.rollNumber;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	unordered_map<student, int, hashFunction> um;
	student s1("A", "B", 50);
	student s2("A", "C", 25);
	student s3("S", "K", 51);
	student s4("W", "T", 12);
	student s5("W", "T", 13);
	um[s1] = 55;
	um[s2] = 20;
	um[s3] = 80;
	um[s4] = 70;
	um[s5] = 88;
	for (auto it : um) {
		cout << "Name : " << it.first.firstName << " " << it.first.lastName << " Roll No : " << it.first.rollNumber << " Marks :" << it.second << endll;
	}
	return 0;
}