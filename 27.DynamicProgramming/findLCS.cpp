/*
 * @Author: MOHIT PATHAK
 * @Date:   2021-10-02 15:10:34
 * @Last Modified by:   MOHIT PATHAK
 * @Last Modified time: 2021-10-03 16:38:02
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int lcs(string& s1, string& s2, int i, int j) {
    if (i == s1.length() or j == s2.length()) return 0;
    if (s1[i] == s2[j])
        return 1 + lcs(s1, s2, i + 1, j + 1);
    else
        return max(lcs(s1, s2, i + 1, j), lcs(s1, s2, i, j + 1));
}

// using bottom up memoization
int lcs2(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    if (i == s1.length() or j == s2.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (s1[i] == s2[j]) return dp[i][j] = 1 + lcs2(s1, s2, i + 1, j + 1, dp);
    int op1 = lcs2(s1, s2, i + 1, j, dp);
    int op2 = lcs2(s1, s2, i, j + 1, dp);
    return dp[i][j] = max(op1, op2);
}

// using top down tabulation
int lcs3(string& s1, string& s2) {
    vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));
    for (int i = 1; i < s1.length() + 1; i++) {
        for (int j = 1; j < s2.length() + 1; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    for (auto v : dp) {
        for (auto it : v) cout << it << " ";
        cout << endll;
    }
    return dp[s1.length()][s2.length()];
}

//==========================================
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2, 0, 0) << endll;

    // using top down dp
    cout << "Using top down dp : " << endll;
    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    cout << lcs2(s1, s2, 0, 0, dp) << endll;
    for (auto v : dp) {
        for (auto it : v) cout << it << " ";
        cout << endll;
    }

    cout << "Using bottom up dp : " << endll;
    cout << lcs3(s1, s2) << endll;
    return 0;
}