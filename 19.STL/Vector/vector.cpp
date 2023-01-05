/*
* @Author: MOHIT PATHAK
* @Date:   2021-08-31 16:49:18
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-08-31 17:14:24
*/


#include<iostream>
#include<vector>


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
	//INITITIALIZATION
	vector<int> v1;
	vector<int>v2(10, 0)	;
	vector<int>v3(v2.begin(), v2.begin() + 5);
	vector<int>v4{1, 2, 3, 4, 5};
	vector<int>v5(v4);

	//size
	v5.reserve(1000);
	cout << v5.size() << endll;
	cout << v5.capacity() << endll;
	cout << v5.max_size() << endll;

	//OTHER METHODS
	v5.push_back(99);
	v4.pop_back();
	v4.insert(v4.begin() + 2, 99);
	v4.insert(v4.begin() + 2, 5, 99);//range
	v4.erase(v4.begin() + 1);
	v4.erase(v4.begin() + 1, v4.begin() + 5);//range
	v2.resize(5);//remaining elements are lost
	v2.resize(15);//added elements are initialized with a 0
	v2.clear();
	if (v2.empty())cout << "this is an empty vector" << endll;
	cout << v3.front() << " " << v3.back() << endll;

	//TRAVERSING
	for (int it : v2)cout << it << " ";
	cout << endll;

	for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++) {
		cout << *it << " ";
	}
	cout << endll;

	for (int i = 0; i < v5.size(); i++) {
		cout << v5[i] << " ";
	}
	cout << endll;

	return 0;
}