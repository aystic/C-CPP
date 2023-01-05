/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-02 16:27:40
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-02 16:56:38
*/

#include<iostream>
#include<stack>

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

	stack<int> st;
	for (int i = 0; i < 5; ++i)
	{
		st.push(i * i);
	}
	while (!st.empty()) {
		cout << st.top() << endll;
		st.pop();
	}
	return 0;
}