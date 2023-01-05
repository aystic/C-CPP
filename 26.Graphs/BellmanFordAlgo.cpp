/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-19 02:57:13
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-19 05:48:20
*/
#include<iostream>
#include<vector>
#include <climits>
using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

vector<int> bellman_ford(int src, int n, vector<vector<int>>&edges) {
	vector<int>dist(n + 1, INT_MAX);
	dist[src] = 0;

	for (int i = 0; i < n - 1; ++i)
	{
		for (auto edge : edges) {
			int u = edge[0];
			int v = edge[1];
			int wt = edge[2];
			if (dist[u] != INT_MAX and (dist[u] + wt < dist[v])) {
				dist[v] = dist[u] + wt;
			}
		}
	}

	//checking for negative wt cycle
	for (auto edge : edges) {
		int u = edge[0];
		int v = edge[1];
		int wt = edge[2];
		if (dist[u] != INT_MAX and (dist[u] + wt < dist[v])) {
			cout << "Negative wt cycle found" << endll;
			exit(0);
		}
	}
	return dist;
}


//==========================================
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int n, m;
	cin >> n >> m;
	vector<vector<int>>edges;
	for (int i = 0; i < m; ++i)
	{
		int x, y, wt;
		cin >> x >> y >> wt;
		edges.push_back({x, y, wt});
	}
	vector<int>dist = bellman_ford(1, n, edges);
	for (int i = 1; i < n + 1; ++i)
	{
		cout << "Edge " << i << " Distance " << dist[i] << endll;
	}
	return 0;
}