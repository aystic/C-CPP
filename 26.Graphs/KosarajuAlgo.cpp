/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-23 01:36:11
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-23 07:30:52
*/
#include<iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void dfs(int src, vector<int>graph[], vector<int>&stack, bool visited[]) {
	visited[src] = 1;
	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			dfs(nbr, graph, stack, visited);
		}
	}
	stack.push_back(src);
}

void dfs2(int src, vector<int>graph[], bool visited[]) {
	visited[src] = 1;
	cout << src << ", ";
	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			dfs2(nbr, graph, visited);
		}
	}
}

void kosaraju(vector<int>graph[], vector<int>rev_graph[], int n) {
	bool visited[n] {};
	vector<int>stack;
	stack.reserve(n);
	for (int it = 0; it < n; it++) {
		if (!visited[it]) {
			dfs(it, graph, stack, visited);
		}
	}
	for (auto& it : visited)it = 0;
	char component = 'A';
	for (int i = stack.size() - 1; i >= 0; i--) {
		if (!visited[stack[i]]) {
			cout << component << " --> ";
			dfs2(stack[i], rev_graph, visited);
			component++;
			cout << endll;
		}
	}
}



//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n;
	cin >> n;
	vector<int> graph[n];
	vector<int>rev_graph[n];
	for (int i = 0; i < n; ++i)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}
	kosaraju(graph, rev_graph, n);
	return 0;
}