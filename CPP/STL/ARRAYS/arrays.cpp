/*
 * @Author: Mohit Pathak 
 * @Date: 2021-08-20 11:53:15 
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-08-20 20:27:43
 */

#include <iostream>
#include <array>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

//==========================================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================

    array<int, 10> arr{11, 22, 33, 44, 55, 66, 77, 88, 99, 0};

    //iterators
    cout << *(arr.begin()) << endll;    //first element
    cout << *(arr.end() - 1) << endll;  //last element
    cout << *(arr.rbegin()) << endll;   //last element
    cout << *(arr.rend() - 1) << endll; //first element

    //capacity
    cout << arr.size() << endll;
    cout << arr.max_size() << endll;
    arr.empty()
        ? cout << "array is empty" << endll
        : cout << "array is not empty" << endll;

    //element access
    cout << arr[5] << endll;
    cout << arr.at(5) << endll;
    cout << arr.front() << endll;
    cout << arr.back() << endll;
    cout << *(arr.data()) << endll; //returns pointer to first element

    //modifiers
    arr.fill(-1); //fills the array with -1
    for (int it : arr)
        cout << it << " ";
    cout << endll;

    array<int, 10> arr1{0, 99, 88, 77, 66, 55, 44, 33, 22, 11};
    arr.swap(arr1); //swaps the content of arr and arr1
    for (int it : arr)
        cout << it << " ";
    cout << endll;
    for (int it : arr1)
        cout << it << " ";
    cout << endll;

    //loops
    array<int, 10>::iterator itr;
    for (itr = arr.begin(); itr != arr.end(); itr++)
    {
        cout << *itr << " ";
    }
    cout << endll;
    for (int it : arr)
    {
        cout << it << " ";
    }
    cout << endll;
    return 0;
}