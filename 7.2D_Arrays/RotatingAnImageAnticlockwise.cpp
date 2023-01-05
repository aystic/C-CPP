/*
 * @Author: pmohit
 * @Date:   2021-06-11 00:29:47
 * @Last Modified by:   pmohit
 * @Last Modified time: 2021-06-11 00:39:46
 */

//#include<bits/stdc++.h>
#include <algorithm>
#include <iostream>

using namespace std;
#define endll '\n'
//--------------------------------------

void display(int arr[100][100], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endll;
    }
}
void rotateTheImage(int arr[100][100], int row, int col) {
    // first reverse all the rows
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            swap(arr[i][j], arr[i][col - 1 - j]);
        }
    }
    // now reverse the array along the diagonal
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i > j) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    display(arr, row, col);
}

void rotateTheImageUsingSTL(int arr[100][100], int row, int col) {
    // reversing all the rows
    for (int i = 0; i < row; ++i) {
        reverse(arr[i], arr[i] + col);
    }
    // reverse the array along the diagonal
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (i > j) {
                swap(arr[i][j], arr[j][i]);
            }
        }
    }
    display(arr, row, col);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //--------------------------------------

    int arr[100][100];
    int row, col;
    cin >> row >> col;
    int count = 1;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            arr[i][j] = count++;
        }
    }
    display(arr, row, col);
    cout << endl;
    rotateTheImageUsingSTL(arr, row, col);

    return 0;
}