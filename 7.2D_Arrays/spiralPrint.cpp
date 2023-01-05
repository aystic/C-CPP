/*
 * @Author: pmohit
 * @Date:   2022-03-22 10:48:54
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2022-03-22 13:03:46
 */
#include <iostream>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(int arr[][5]) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endll;
    }
}

void spiralPrint(int arr[][5]) {
    int rowStart = 0, rowEnd = 4, colStart = 0, colEnd = 4;
    while (rowStart <= rowEnd and colStart <= colEnd) {
        // 1.PRINTING THE UPPER PART
        for (int col = colStart; col <= colEnd; col++) {
            cout << arr[rowStart][col] << " ";
        }
        rowStart++;
        // 2.PRINTING THE RIGHT PART
        for (int row = rowStart; row <= rowEnd; row++) {
            cout << arr[row][colEnd] << " ";
        }
        colEnd--;
        // 3.PRITING THE BOTTOM PART
        if (colStart <= colEnd) {
            for (int col = colEnd; col >= colStart; col--) {
                cout << arr[rowEnd][col] << " ";
            }
            rowEnd--;
        }
        // 4.PRINTING THE LEFT PART
        if (rowStart <= rowEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                cout << arr[row][colStart] << " ";
            }
            colStart++;
        }
    }
}

//==========================================
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================
    int arr[5][5]{{1, 2, 3, 4, 5},
                  {5, 6, 7, 8, 9},
                  {9, 10, 11, 12, 13},
                  {13, 14, 15, 16, 17},
                  {18, 19, 20, 21, 22}};
    display(arr);
    cout << endll;
    spiralPrint(arr);
    return 0;
}