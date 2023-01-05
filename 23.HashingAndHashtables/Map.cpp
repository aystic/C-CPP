/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-07 22:21:15
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-07 22:31:30
*/

#include<iostream>
#include<map>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


ostream& operator<<(ostream& os, map<string, int>& m) {
	for (auto it : m)cout << "(" << it.first << ", " << it.second << ")" << endll;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	map<string, int> m;
	//Insertion
	m["Banana"] = 20;
	m.insert({"Apple", 100});
	pair<string, int> p("Mango", 40);
	m.insert(p);
	m.insert(make_pair("Peach", 150));
	cout << m;

	//Search
	map<string, int>::iterator it = m.find("Peach");
	if (it != m.end()) {
		cout << "The price of Peach is " << (*it).second << endll;
	} else {
		cout << "Fruit not found" << endll;
	}

	if (m.count("Strawberry")) {
		cout << "Strawberry is present" << endll;
	} else {
		cout << "Strawberry is not present" << endll;
	}

	//Deletion
	m.erase("Banana");
	cout << m;

	//Updation
	m["Apple"] += 10;
	cout << m;
	return 0;
}