/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-19 07:38:30
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-20 08:08:36
*/
#include<iostream>
#include <vector>
#include <bitset>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================
#define inf 1e5

int tsp_helper(int src, int current, int cities, int paths[][20], bitset<4>&mask) {
	// cout << mask << endll;
	if (mask == ((1 << cities) - 1)) {
		return paths[current][src];
	}
	int ans = inf;
	for (int i = 0; i < cities; i++) {
		if (mask[i] == 0) { //city is not visited yet
			mask[i] = 1;
			int tempAns = paths[current][i] + tsp_helper(src, i, cities, paths, mask);
			ans = min(ans, tempAns);
			mask[i] = 0;
		}
	}
	return ans;
}

int tsp(int cities, int paths[][20]) {
	int answer = inf;
	bitset<4> mask;
	for (int src = 0; src < cities; ++src)
	{
		mask[src] = 1;
		int tempAns = tsp_helper(src, src, cities, paths, mask);
		answer = min(answer, tempAns);
		mask[src] = 0;
	}
	return answer;
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
	int paths[20][20];
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			int length;
			cin >> length;
			if (length != -1)paths[i][j] = length;
			else paths[i][j] = inf;
		}
	}
	cout << tsp(n, paths) << endll;
	return 0;
}
/*
4
0 20 42 25
20 0 30 34
42 30 0 10
25 34 10 0
*/