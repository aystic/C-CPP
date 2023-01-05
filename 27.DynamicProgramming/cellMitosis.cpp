/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-05 17:55:51
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-05 18:00:56
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int solveCellMitosis(int n, int x, int y, int z) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if ((i & 1) == 1) {  // odd
            dp[i] = min(dp[i - 1] + y, dp[(i + 1) / 2] + x + z);
        } else {  // even
            dp[i] = min(dp[i / 2] + x, dp[i - 1] + y);
        }
    }
    for (auto it : dp) cout << it << " ";
    cout << endll;
    return dp[n];
}

//==========================================
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================

    int n, x, y, z;
    cin >> n >> x >> y >> z;
    cout << solveCellMitosis(n, x, y, z) << endll;
    return 0;
}