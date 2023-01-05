/*
* @Author: Mohit Pathak
* @Date:   2021-09-06 01:24:09
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-09-06 01:33:15
*/

#include<iostream>
#include<set>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class compare {
public:
	bool operator()(pair<string, int>a, pair<string, int>b) {
		return a.second < b.second;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	multiset<pair<string, int>, compare> m({{"A", 100}, {"B", 50}, {"C", 35}});
	// m.insert({"A", 10});
	// m.insert({"C", 100});
	// m.insert({"E", 40});
	// m.insert({"D", 25});
	// m.insert({"B", 55});
	for (auto it : m) {
		cout << it.first << " " << it.second << endll;
	}
	return 0;
}
