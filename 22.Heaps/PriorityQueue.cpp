/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-06 23:34:32
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-06 23:47:18
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

	// priority_queue<int> pq;//bigger element has priority(maxheap)
	priority_queue<int, vector<int>, greater<int>> pq; //smaller element has priority(minheap)
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int data;
		cin >> data;
		pq.push(data);
	}

	while (!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	return 0;
}