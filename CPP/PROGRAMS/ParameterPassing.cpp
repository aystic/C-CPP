/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 11:43:04
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 11:47:50
*/
#include<iostream>
using namespace std;

int sum(int &a,int &b){
	return (++a)+b;
}

int main(){
   int a=1,b=99;
   // cout<<sum(a,b)<<endl;//pass by value
   // cout<<sum(&a,&b)<<endl;//pass by address
   cout<<sum(a,b)<<endl;//pass by refrence
   cout<<a<<endl;
   return 0;
}	