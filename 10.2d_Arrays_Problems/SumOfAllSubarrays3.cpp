/*
 * @Author: Mohit Pathak
 * @Date:   2021-06-18 00:13:36
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2022-03-22 16:36:33
 */

//#include<bits/stdc++.h>
#include <iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void SumOfAllSubarrays(int **arr, int row, int col) {
    int sum = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            int tl = (i + 1) * (j + 1);      // ALL POSSIBLE TOPLEFT
            int br = (row - i) * (col - j);  // ALL POSSIBLE BOTTOM RIGHT
            sum += (tl * br) * arr[i][j];    // ALL POSSIBLE ARRAYS
        }
    }
    cout << sum << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //--------------------------------------

    int row, col;
    cin >> row >> col;
    int **arr = new int *[row];
    for (int i = 0; i < row; ++i) {
        arr[i] = new int[col];
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cin >> arr[i][j];
        }
    }
    SumOfAllSubarrays(arr, row, col);
    return 0;
}