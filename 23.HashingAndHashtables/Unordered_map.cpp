/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-07 22:36:51
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-07 22:39:29
*/
#include<iostream>
#include<unordered_map>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

ostream& operator<<(ostream& os, unordered_map<string, int>& m) {
	for (auto it : m)cout << "(" << it.first << ", " << it.second << ")" << endll;
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	unordered_map<string, int> um;

	//Insertion
	um["Banana"] = 20;
	um.insert({"Apple", 100});
	pair<string, int> p("Mango", 40);
	um.insert(p);
	um.insert(make_pair("Peach", 150));
	cout << um;

	//Search
	unordered_map<string, int>::iterator it = um.find("Peach");
	if (it != um.end()) {
		cout << "The price of Peach is " << (*it).second << endll;
	} else {
		cout << "Fruit not found" << endll;
	}

	if (um.count("Strawberry")) {
		cout << "Strawberry is present" << endll;
	} else {
		cout << "Strawberry is not present" << endll;
	}

	//Deletion
	um.erase("Banana");
	cout << um;

	//Updation
	um["Apple"] += 10;
	cout << um;
	return 0;
}