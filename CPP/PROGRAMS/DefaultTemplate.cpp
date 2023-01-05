/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 10:10:25
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 10:11:46
*/
#include<iostream>
using namespace std;

int add(int a,int b,int c=0){
	return a+b+c;
}

int main(){
   cout<<add(5,10);
   cout<<endl<<add(1,2,97)<<endl;
   return 0;
}	