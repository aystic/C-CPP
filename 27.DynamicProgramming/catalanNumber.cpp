/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-06 01:41:35
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-15 01:45:33
 */
#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int BST(int n, vector<int>& dp) {
    if (dp[n] != 0) return dp[n];
    for (int i = n; i >= 1; --i) {
        dp[n] += BST(i - 1, dp) * BST(n - i, dp);
    }
    return dp[n];
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
    int answer;
    vector<int> dp(n + 1, 0);
    dp[0] = dp[1] = 1;
    cout << "Binary Search Trees : " << (answer = BST(n, dp)) << endll;
    cout << "Unlabelled Binary Trees : " << answer << endll;
    cout << "Binary Trees : " << n * answer << endll;
    return 0;
}