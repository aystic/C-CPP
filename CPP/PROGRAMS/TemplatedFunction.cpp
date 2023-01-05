/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 09:48:11
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 10:42:31
*/
#include<iostream>
using namespace std;

template <class T>
T sum(T a,T b){
	return a+b;
}

int main(){
   int a;
   float b;
   a=sum(99,1);
   b=sum(101.1f,98.9f);
   cout<<a<<" "<<b<<endl;	
   char c=sum(50,50);
   cout<<c<<endl;




    return 0;
}	