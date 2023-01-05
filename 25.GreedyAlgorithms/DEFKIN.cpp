/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-10 17:25:11
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-11 18:08:40
*/
#include<bits/stdc++.h>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool comparelen(pair<int, int>p1, pair<int, int>p2) {
	return p1.first < p2.first;
}
bool comparebre(pair<int, int>p1, pair<int, int>p2) {
	return p1.second < p2.second;
}



//==========================================
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
//==========================================

	int t;
	cin >> t;
	while (t--) {
		int w, h, n;
		cin >> w >> h >> n;
		if (!n) {
			cout << w*h << endll;
			continue;
		}
		vector<pair<int, int>>tower;
		tower.push_back({0, 0});
		int x, y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			tower.push_back({x, y});
		}
		tower.push_back({w + 1, h + 1});
		int maxl = INT_MIN;
		int maxb = INT_MIN;
		sort(tower.begin(), tower.end(), comparelen);
		int xprev = tower[0].first, yprev = tower[0].second;
		for (int i = 1; i < n + 2; i++) {
			maxl = max((tower[i].first - xprev - 1), maxl);
			xprev = tower[i].first;
		}
		sort(tower.begin(), tower.end(), comparebre);
		for (int i = 1; i < n + 2; i++) {
			maxb = max((tower[i].second - yprev - 1), maxb);
			yprev = tower[i].second;
		}
		cout << maxl*maxb << endll;
	}

	return 0;
}