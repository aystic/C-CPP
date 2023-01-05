/*
* @Author: MOHIT PATHAK
* @Date:   2021-09-09 19:06:36
* @Last Modified by:   MOHIT PATHAK
* @Last Modified time: 2021-09-09 21:46:21
*/
#include<iostream>
#include<algorithm>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void makeChange(int coins[], int money, int n) {
	int answer = 0;
	while (money > 0) {
		int idx = upper_bound(coins, coins + n, money) - 1 - coins;
		cout << coins[idx] << " + ";
		money -= coins[idx];
		answer++;
	}
	cout << endll;
	cout << answer << endll;
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
	int coins[] {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
	makeChange(coins, n, sizeof(coins) / sizeof(int));
	return 0;
}