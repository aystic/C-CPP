/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-03 10:21:30
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-03 10:27:46
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

	int freq[26] {};
	queue<char> q;
	char ch;
	cin >> ch;
	while (ch != '.') {
		//updation
		q.push(ch);
		freq[ch - 'a']++;

		//printing
		while (!q.empty()) {
			if (freq[q.front() - 'a'] == 1) {
				cout << q.front() << endll;
				break;
			} else {
				q.pop();
			}
		}
		if (q.empty()) {
			cout << "-1" << endll;
		}
		cin >> ch;
	}
	return 0;
}