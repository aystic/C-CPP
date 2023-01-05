/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-06 23:50:26
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-06 23:58:26
*/
#include<iostream>
#include<queue>
#include<string>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class person {
public:
	string name;
	int age;
	person() {

	}
	person(string s, int age) {
		name = s;
		this->age = age;
	}
};


class compare {
public:
	bool operator()(person a, person b) {
		return a.age < b.age; //priotising based on the age
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	priority_queue<person, vector<person>, compare> pq;
	pq.push({"A", 17});
	pq.push({"B", 90});
	pq.push({"C", 55});
	pq.push({"D", 30});
	pq.push({"E", 35});
	while (!pq.empty()) {
		cout << pq.top().name << " " << pq.top().age << endll;
		pq.pop();
	}
	return 0;
}