/*
* @Author: pmohit
* @Date:   2021-02-01 12:19:06
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-01 12:24:34
*/

#include<iostream>

using namespace std;

void swapbyvalue(int a, int b){
	int temp=b;
	b=a;
	a=temp;
}

void swapbyaddress(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void swapbyreference(int &a,int &b){//becomes and inline function and no new call stack is created
	int temp=b;
	b=a;
	a=temp;
}

int main(){
	int a=99,b=1;
	swapbyvalue(a,b);
	cout<<a<<" "<<b<<endl;
	swapbyaddress(&a,&b);
	cout<<a<<" "<<b<<endl;
	swapbyreference(a,b);
	cout<<a<<" "<<b<<endl;
	return 0;
}
