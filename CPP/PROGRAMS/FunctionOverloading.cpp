#include<iostream>
using namespace std;

int add(int a, int b){
	return a+b;
}

int add(int a, int b, int c){
	return a+b+c;
}

int main(){
	cout<<add(1,99)<<endl;
	cout<<add(2,1,997)<<endl;


	return 0;
}