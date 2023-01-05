/*
 * @Author: Mohit Pathak
 * @Date:   2021-05-31 13:50:45
 * @Last Modified by:   Mohit Pathak
 * @Last Modified time: 2021-05-31 13:50:45
 */

//#include<bits/stdc++.h>
#include <stdlib.h>

#include <iomanip>
#include <iostream>
#include <string>
// #include <typeinfo>
using namespace std;
#define endll '\n'
//--------------------------------------

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //--------------------------------------
    /* cout << setprecision(3) << 3.23232 << endll;
    cout << setbase(8) << 49 << endll;
    cout << setbase(16) << 49 << endll;
    string mystring = "21212";
    int mynumber;
    stringstream(mystring) >> mynumber;
    cout << setbase(10) << mynumber << endll; */
    /* int n = 10;
start:
    cout << n-- << endll;
    if (n > 0) goto start;
    cout << "Lift off!" << endll; */
    int myNumber = 10;
    char ch = 'a';
    int *myNumberPtr = &myNumber;
    char *chPtr = &ch;
    cout << *myNumberPtr << " " << *chPtr << endll;
    cout << typeid(myNumberPtr).name() << endll;
    return 0;
}