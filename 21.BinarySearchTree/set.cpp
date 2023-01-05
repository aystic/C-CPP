/*
* @Author: Mohit Pathak
* @Date:   2021-09-05 22:26:51
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-06 00:50:51
*/
#include<iostream>
#include<set>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(set<pair<int, int>>s) {
	for (auto it : s) {
		cout << it.first << " " << it.second << endll;
	}
	cout << endll;
}


ostream& operator<<(ostream& os, set<pair<int, int>> s) {
	display(s);
	return os;
}

//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	// int arr[] {1, 2, 3, 3, 4, 5, 8, 1, 3, 5, 10};
	// int n = sizeof(arr) / sizeof(int);
	// set<int> s;
	// for (int i = 0; i < n; ++i)
	// {
	// 	s.insert(arr[i]);
	// }
	// cout << s;
	// s.erase(10);
	// cout << s;
	// set<int>::iterator it;
	// it = s.find(4);
	// s.erase(it);
	// cout << s;

	set<pair<int, int>>s;
	s.insert({1, 2});
	s.insert({1, 6});
	s.insert({2, 6});
	s.insert({3, 7});
	s.insert({10, 11});
	s.insert({9, 99});
	s.insert({21, 21});
	s.insert({0, 0});
	cout << s;
	pair<int, int> p({1, 2});
	cout << s.lower_bound(p)->first << " " << s.lower_bound(p)->second << endll;
	cout << s.upper_bound(p)->first << " " << s.upper_bound(p)->second << endll;


	return 0;
}