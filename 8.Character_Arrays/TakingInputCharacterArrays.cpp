/*
* @Author: Mohit Pathak
* @Date:   2021-06-11 09:57:45
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-06-11 10:23:22
*/

//#include<bits/stdc++.h>
#include<iostream>

using namespace std;
#define endll '\n'
//--------------------------------------





int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//--------------------------------------

	char arr[100] {"Hello world"};//\0 IS ADDED AUTOMATICALLY AT THE END
	cout << arr << endll; //WE WILL GET THE WHOLE CONTENTS OF THE ARRAY UNTIL A '\0' IS FOUND
	//IT IS BECAUSE OF OPERATOR OVELOADING OF THE << OPERATORS IN
	//CASE OF CHAR ARRAYS
	int arr1[100] {11, 22, 33, 44, 55, 66, 77, 88, 99, 0};
	cout << arr1 << endl; //WE WILL GET THE ADDRESS OF THE FIRST ELEMENT
	cout << *arr1 << endl;//WE WILL GET THE VALUE STORED AT THE FIRST ADDRESS

	char arr2[100];
	// cin >> arr2; //VALID; TREATES SPACE AS A DELIMETER; '\0' IS AUTOMATICALLY ADDED
	// cin.getline(arr2, 100); //DEFAULT DELIMETER IS \0; TAKES SPACES AS WELL
	cin.getline(arr2, 100, '!'); //DELIMETER IS '!'; TAKES SPACES AS WELL
	cout << arr2 << endl; //VALID


	return 0;
}