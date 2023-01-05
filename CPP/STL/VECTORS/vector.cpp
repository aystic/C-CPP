/*
 * @Author: Mohit Pathak 
 * @Date: 2021-08-21 12:19:01 
 * @Last Modified by: Mohit Pathak
 * @Last Modified time: 2021-08-21 13:04:07
 */

#include <iostream>
#include <vector>

using namespace std;
#define endll '\n'
typedef long long ll;
typedef long long unsigned llu;
//==========================================

void display(vector<int> &v)
{
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endll;
}

//==========================================
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    //==========================================
    //INITIALIZATION

    vector<int> v1; //default
    display(v1);

    vector<int> v2(10, 0); //fill
    display(v2);

    vector<int> v3(v2.begin(), v2.begin() + 5); //range
    display(v3);

    vector<int> v4(v3); //copy
    display(v4);

    vector<int> v5({11, 22, 33, 44, 55}); //using initialiszer list
    display(v5);

    int arr[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    vector<int> v6(arr, arr + 10); //from array
    display(v6);

    vector<int> v7(2, 0); //using = operator
    display(v7);
    v7 = v5;
    display(v7);

    //ITERATORS
    cout << *(v5.begin()) << endll;
    cout << *(v5.end() - 1) << endll;
    cout << *(v5.rbegin()) << endll;
    cout << *(v5.rend() - 1) << endll;

    //CAPACITY
    vector<int> v8{11, 22, 33};
    cout << v8.size() << endll;     //actual size
    cout << v8.max_size() << endll; //max no of elements the vector can hold

    vector<int> v9{11, 22};
    v9.resize(1);    //vector becomes 11
    v9.resize(3);    //vector becomes 11,0,0
    v9.resize(5, 1); //vector becomes 11,0,0,1,1
    display(v9);

    v9.empty() ? cout << "vector is empty" << endll : cout << "vector is not empty" << endll;

    v9.reserve(10); //increases the capacity to 10

    cout << v9.capacity() << endll; //capacity=10
    cout << v9.size() << endll;     //size is 5
    v9.shrink_to_fit();             //makes capacity=size
    cout << v9.capacity() << endll; //capacity is 5

    //ELEMENT ACCESS
    cout << v9.front() << endll;
    cout << v9.back() << endll;
    cout << v9.at(0) << endll;
    cout << v9[0] << endll;
    cout << *(v9.data()) << endll; //Returns a direct pointer to the memory array

    //MODIFIERS
    vector<int> v10(5, 0);
    display(v10);
    v10.assign(v9.begin(), v9.end()); //range
    display(v10);
    v10.assign(10, -1); //fill
    display(v10);
    v10.assign({1, 2, 3, 4, 5}); //initializer list
    display(v10);

    //

    return 0;
}