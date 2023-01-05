#include<iostream>
using namespace std;

void Hello(char a[]){
	cout<<"Hello "<<a<<"!"<<" How are you?"<<endl;
}

void SayHello(char a[], void(&Hello)(char a[])){//Declaration of the SayHello function
	Hello(a);//Use of Hello function inside the Say hello function
}

int main(){
	char a[20];
	cin>>a;
	SayHello(a,Hello);//Passing Hello function as a parameter to function SayHello
	return 0;
}