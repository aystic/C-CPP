/*
 * @Author: Mohit Pathak
 * @Date: 2021-10-05 20:14:21
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-10-05 20:22:17
 */
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

int solution(vector<int>& arr) {
    int n = arr.size();
    vector<vector<pair<int, int>>> dp(
        arr.size(), vector<pair<int, int>>(arr.size(), make_pair(0, 0)));
    int i = 0, j = 0;
    while (i < n and j < n) {
        dp[i][j] = make_pair(0, arr[i]);
        i++;
        j++;
    }
    int row = 0, col = 1;
    while (col < n) {
        i = row;
        j = col;
        while (i < n and j < n) {
            int color = 0, smoke = 0;
            for (int k = i + 1; k <= j; k++) {
                smoke = (dp[i][k - 1].first + dp[k][j].first) +
                        dp[i][k - 1].second * dp[k][j].second;
                color = (dp[i][k - 1].second + dp[k][j].second) % 100;
                if (dp[i][j] == make_pair(0, 0))
                    dp[i][j] = make_pair(smoke, color);
                else {
                    if (dp[i][j].first > smoke) {
                        dp[i][j] = make_pair(smoke, color);
                    }
                }
            }
            i++;
            j++;
        }
        col++;
    }
    return dp[0][n - 1].first;
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

    int n;
    while ((cin >> n)) {
        vector<int> arr;
        arr.reserve(n);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        cout << solution(arr) << endll;
    }
    return 0;
}