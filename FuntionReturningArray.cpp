/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 12:57:38
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 13:02:52
*/

#include<iostream>

using namespace std;

// int[] create(int n){
// 	int *p=new int[n];
// 	return p;
// }

int * createnew(int n){
	int *p=new int[n];
	for (int i = 0; i < n; ++i)
	{
		p[i]==0;
	}
	return p;
}

int main(){
	int n=5;
	int *arr;
	// arr=create(n);
	int *arr2;
	arr2=createnew(n);
	// for (int i = 0; i < n; ++i)
	// {
	// 	cout<<arr[i]<<" ";
	// }
	// cout<<endl;
	for (int i = 0; i < n; ++i)
	{
		cout<<arr2[i]<<" ";
	}
	cout<<endl;
	return 0;
}
