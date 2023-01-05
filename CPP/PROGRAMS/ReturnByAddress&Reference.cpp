/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 11:48:28
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 11:57:57
*/
#include<iostream>
using namespace std;

//Return by address
// int* sum(int a,int b){
// 	int *sum=new int;
// 	*sum=a+b;
// 	return sum;
// }

//Return by Reference
int& add(int &a,int &b,int &sum){
	sum=a+b;
	return sum;
}

int main(){
	// int a=1,b=99;
	// int *add=sum(a,b);
	// cout<<*add<<endl;
	int a=1,b=99;
	int sum=0;
	cout<<add(a,b,sum)<<endl;
    return 0;
}	