/*
* @Author: Mohit Pathak
* @Date:   2021-02-01 12:24:48
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 12:32:19
*/

#include<iostream>

using namespace std;

void incrementbyone(int a[],int n){
	for (int i = 0; i < n; ++i)
	{
		a[i]++;
	}
}

void decrementbyone(int *a,int n){
	for (int i = 0; i < n; ++i)
	{
		(*(a+i))--;
	}

}

void display(int *a,int n){
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;

}

int main(){
	int arr[5] {0,1,2,3,4};
	int n=5;
	display(arr,n);
	incrementbyone(arr,n);
	display(&arr[0],n);
	decrementbyone(arr,n);
	display(arr,n);
	return 0;
}
