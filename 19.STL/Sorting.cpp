/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-31 07:29:26
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-31 07:34:25
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================


bool compareBasedOnName(pair<string, int>p1, pair<string, int>p2) {
	return p1.first < p2.first;
}

bool compareBasedOnPrice(pair<string, int>p1, pair<string, int>p2) {
	return p1.second < p2.second;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	vector <pair<string, int>> fruits;
	fruits.push_back({"mango", 50});
	fruits.push_back({"apple", 100});
	fruits.push_back({"banana", 20});
	fruits.push_back({"pineapple", 120});
	for (auto it : fruits) {
		cout << it.first << " " << it.second << endll;
	}
	cout << endll;
	sort(fruits.begin(), fruits.end(), compareBasedOnName);
	for (auto it : fruits) {
		cout << it.first << " " << it.second << endll;
	}
	cout << endll;
	sort(fruits.begin(), fruits.end(), compareBasedOnPrice);
	for (auto it : fruits) {
		cout << it.first << " " << it.second << endll;
	}
	return 0;
}