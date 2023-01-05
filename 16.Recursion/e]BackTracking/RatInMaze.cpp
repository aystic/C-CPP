/*
* @Author: pmohit
* @Date:   2021-08-03 19:25:21
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-08-04 00:35:52
*/

//==========================================
//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

bool findAllPaths(char arr[][100], int m, int n, int i, int j) {
        //we need to print the arr if rat reaches the destination
        if (i == m - 1 and j == n - 1) {
                if (arr[i][j] != 'X') {
                        arr[i][j] = '1';
                }
                //print
                for (int i = 0; i < m; ++i)
                {
                        for (int k = 0; k < n; ++k)
                        {
                                cout << arr[i][k] << " ";
                        }
                        cout << endll;
                }
                cout << endll;
                //backtracking
                arr[i][j] = '0';
                return true;
        }
        if (i == m or j == n or arr[i][j] == 'X' ) {
                return false;
        } else {
                arr[i][j] = '1';
                bool pathInRight = findAllPaths(arr, m, n, i, j + 1);
                bool pathDown = findAllPaths(arr, m, n, i + 1, j);
                arr[i][j] = '0';
        }
        return true;
}


//==========================================
int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        //==========================================

        int m, n;
        char arr[100][100] {};
        cin >> m >> n;
        for (int i = 0; i < m; ++i)
        {
                for (int j = 0; j < n; ++j)
                {
                        cin >> arr[i][j];
                }
        }
        findAllPaths(arr, m, n, 0, 0);
        return 0;
}