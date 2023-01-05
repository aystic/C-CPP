#include<iostream>
using namespace std;

int main(){
	int a=10,b=20;
	int *x=&a,&y=b;
	cout<<a<<endl;
	cout<<b<<endl;
	cout<<x<<endl;
	cout<<y<<endl;
	y=a;
	cout<<y<<endl;

	return 0;
}