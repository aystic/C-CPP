/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-19 06:06:04
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-19 06:33:46
*/
#include<iostream>
#include <vector>
#include<climits>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

#define inf INT_MAX

vector<vector<int>> floydWarshall(vector<vector<int>>& graph) {
	vector<vector<int>>dist(graph);
	int n = graph.size();
	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i != j and (i != k or j != k)) {
					if ((dist[i][k] != inf and dist[k][j] != inf) and dist[i][j] > dist[i][k] + dist[k][j]) {
						dist[i][j] = dist[i][k] + dist[k][j];
					}
				}
			}
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

	vector<vector<int>>graph = {{0, inf, -2, inf},
		{4, 0, 3, inf},
		{inf, inf, 0, 2},
		{inf, -1, inf, 0}
	};
	graph = floydWarshall(graph);
	int n = graph.size();
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << graph[i][j] << " ";
		}
		cout << endll;
	}
	cout << endll;
	return 0;
}