/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-18 18:52:55
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-19 01:19:03
*/
#include<iostream>
#include <queue>
#include <vector>
#include<list>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class graph {
	vector<pair<int, int>>*v;
	int n;
public:
	graph(int n) {
		this->n = n;
		v = new vector<pair<int, int>>[n];
	}
	void addEdge(int x, int y, int wt) {
		v[x].push_back(make_pair(y, wt));
		v[y].push_back(make_pair(x, wt));
	}
	void display() {
		for (int i = 0; i < n; ++i)
		{
			for (auto it : v[i]) {
				cout << it.first << " " << it.second << ", ";
			}
			cout << endll;
		}
		cout << endll;
	}

	int prims_mst() {
		priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
		bool visited[n] {};
		int answer = 0;
		q.push({0, 0});
		while (!q.empty()) {
			int curr = q.top().second;
			int wt = q.top().first;
			q.pop();
			if (!visited[curr]) {
				answer += wt;
				visited[curr] = true;
				for (auto edge : v[curr]) {
					if (!visited[edge.first]) {
						q.push({edge.second, edge.first});
					}
				}
			}
		}
		return answer;
	}

};


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n, m;
	cin >> n >> m;
	graph g(n);
	for (int i = 0; i < m; ++i)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		g.addEdge(x - 1, y - 1, wt);
	}
	cout << g.prims_mst() << endll;
	return 0;
}