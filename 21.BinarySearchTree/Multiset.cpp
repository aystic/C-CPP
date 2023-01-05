/*
* @Author: Mohit Pathak
* @Date:   2021-09-06 00:51:30
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-06 01:21:48
*/

#include<iostream>
#include<set>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================





//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int arr[] {1, 2, 3, 5, 5, 6, 10, 10};

	multiset<int> m{arr, arr + 8};

	for (auto it : m) {
		cout << it << " ";
	}
	cout << endll;

	m.erase(10);//all occurances are erased
	for (auto it : m) {
		cout << it << " ";
	}

	cout << endll << m.count(5) << endll;

	multiset<int>::iterator it = m.find(5);//iterator to first occurance of the element
	cout << *it << endll;

	pair<multiset<int>::iterator, multiset<int>::iterator> itr = m.equal_range(5);//gives the iterator to the first and the last occurance of the element
	for (auto it = itr.first; it != itr.second; it++) {
		cout << *it << " ";
	}
	cout << endll;

	for (auto it = m.upper_bound(2); it != m.lower_bound(6); it++) {
		cout << *it << " ";//prints all the numbers between (2,6)
	}
	cout << endll;
	return 0;
}
