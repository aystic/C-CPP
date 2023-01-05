/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-17 21:31:16
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-19 01:14:28
*/
#include<iostream>
#include<list>
#include<vector>
#include<tuple>
#include<algorithm>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class DSU {
	int *parent;
	int*rank;
public:
	DSU(int v) {
		parent = new int[v];
		rank = new int[v];
		for (int i = 0; i < v; ++i)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
	}
	int find(int i) {
		if (parent[i] == -1) {
			return i;
		}
		return parent[i] = find(parent[i]);
	}
	void unite(int x, int y) {
		int s1 = find(x);
		int s2 = find(y);
		if (s1 != s2 or s1 == s2 == -1) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			} else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
		return;
	}
};

class graph {
	vector<tuple<int, int, int>>g;
	int v;
public:
	graph(int n) {
		this->v = n;
	}
	void addEdge(int x, int y, int w) {
		g.push_back({w, x, y});
	}
	int kruskal() {
		DSU d(v);
		int answer = 0;
		//1.sort
		sort(g.begin(), g.end());
		//2.pick lowest cost edge that doesn't form cycle
		for (auto edge : g) {
			int x = get<1>(edge);
			int y = get<2>(edge);
			int w = get<0>(edge);
			if (d.find(x) != d.find(y) or (d.find(x) == -1 and d.find(y) == -1)) {
				d.unite(x, y);
				answer += w;
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
	cout << g.kruskal() << endll;
	return 0;
}