/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-17 05:56:20
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-18 18:52:55
*/
#include<iostream>
#include <list>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

class graph {
	list<pair<int, int>>l;//edgelist
	int v;
public:
	graph(int v) {
		this->v = v;
	}
	void addEdge(int x, int y) {
		l.push_back({x, y});
	}
	int find_set(int i, int parent[]) {
		if (parent[i] == -1) {
			return i;
		}
		return find_set(parent[i], parent);
	}
	void union_set(int x, int y, int parent[]) {
		int s1 = find_set(x, parent);
		int s2 = find_set(y, parent);
		if (s1 != s2 or s1 == s2 == -1) {
			parent[s2] = s1;
		}
		return;
	}
	bool checkCycle() {
		int *parent = new int[v];
		for (int i = 0; i < v; ++i)
		{
			parent[i] = -1;
		}
		for (auto edge : l) {
			int x = edge.first;
			int y = edge.second;
			int s1 = find_set(x, parent);
			int s2 = find_set(y, parent);
			if (s1 != s2 or (s1 ==  s2 == -1)) {
				union_set(x, y, parent);
			} else return true;
		}
		return false;
	}
	int find_set_optimised(int i, int parent[]) {
		if (parent[i] == -1) {
			r]eturn i;
		}
		return parent[i] = find_set_optimised(parent[i], parent);
	}
	void union_set_optimised(int x, int y, int parent[], int rank[]) {
		int s1 = find_set_optimised(x, parent);
		int s2 = find_set_optimised(y, parent);
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

	bool checkCycle_optimised() {
		int *parent = new int[v];
		int *rank = new int[v];
		bool cyclePresent = false;
		for (int i = 0; i < v; ++i)
		{
			parent[i] = -1;
			rank[i] = 1;
		}
		for (auto edge : l) {
			int x = edge.first;
			int y = edge.second;
			int s1 = find_set_optimised(x, parent);
			int s2 = find_set_optimised(y, parent);
			if (s1 != s2 or (s1 ==  s2 == -1)) {
				union_set_optimised(x, y, parent, rank);
			} else cyclePresent = true;
		}
		for (int i = 0; i < v; ++i)
		{
			cout << parent[i] << " ";
		}
		cout << endll;
		for (int i = 0; i < v; ++i)
		{
			cout << rank[i] << " ";
		}
		cout << endll;
		return cyclePresent;
	}

};



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	graph g(7);
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(0, 4);
	g.addEdge(5, 6);
	g.addEdge(2, 5);
	g.addEdge(2, 6);
	cout << g.checkCycle_optimised() << endll;
	return 0;
}