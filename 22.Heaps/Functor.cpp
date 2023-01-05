/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-06 23:47:56
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-06 23:49:11
*/

#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class functor {
public:
	void operator()() {
		cout << "Inside functor" << endll;
	}
};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	functor f;
	f();//looks like function but it is a result of operator overloading
	return 0;
}