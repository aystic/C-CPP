/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 09:31:50
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-03 09:42:11
*/

#include<iostream>
#include<queue>

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

	queue<int> q;
	for (int i = 0; i < 6; ++i)
	{
		q.push(i * i);
	}

	while (!q.empty()) {
		cout << q.front() << " <-- ";
		q.pop();
	}
	return 0;
}