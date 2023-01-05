#include<iostream>
using namespace std;

void sayhello(char a[]){
	cout<<"Hello "<<a<<"!"<<endl;
}


int main(){
	char a[20];
	cin>>a;	\
	sayhello(a);
	return 0;
}