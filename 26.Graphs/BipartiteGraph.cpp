/*
 * @Author: MOHIT PATHAK
 * @Date:   2021-09-22 03:53:13
 * @Last Modified by:   MOHIT PATHAK
 * @Last Modified time: 2021-09-22 05:10:33
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool isBipartiteHelper(vector<int> edges[], int parent, int color,
                       int visited[]) {
    visited[parent] = color;
    for (auto nbr : edges[parent]) {
        if (visited[nbr] == 0) {  // not visited yet
            bool check = isBipartiteHelper(edges, nbr, 3 - color, visited);
            if (!check) return false;
        } else {
            if (nbr != parent and visited[nbr] == color) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(int n, int m, vector<int> edges[]) {
    int visited[n] {};
    bool check = isBipartiteHelper(edges, 0, 1, visited);
    for (int i = 0; i < n; ++i)
    {
        cout << "Node " << i << " Color --> " << visited[i] << endll;
    }
    return check;
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
    vector<int> edges[n];
    while (m--) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    if (isBipartite(n, m, edges)) {
        cout << "The graph is Bipartite" << endll;
    } else {
        cout << "The graph is not a Bipartite graph" << endll;
    }
    return 0;
}