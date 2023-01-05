/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 11:16:19
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 12:21:39
*/

#include<iostream>
#include<list>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

template <class T>
ostream& operator<<(ostream&os, list<T> l) {
	for (T it : l) {
		cout << it << " -> ";
	}
	cout << endll;
	return os;
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	list<string> l({"apple", "banana", "kiwi", "pineapple"});
	l.push_front("orange");
	l.push_back("peach");
	l.reverse();
	l.sort();
	l.pop_front();
	l.pop_back();
	l.push_back("banana");
	l.remove("banana");//removes all the occurences of banana
	l.push_back("carrot");
	l.push_back("lemon");
	l.push_back("watermelon");
	cout << l;
	auto it = l.begin();//to remove 3rd element
	for (int i = 0; i < 3; ++i)
	{
		it++;
	}
	l.erase(it);
	cout << l;
	it = l.begin();
	it++;
	l.insert(it, "papaya");
	cout << l;
	return 0;
}