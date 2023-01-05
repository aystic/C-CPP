#include<iostream>
using namespace std;

int Factorial(int n){
	int factorial=1;
	while(n>0){
		factorial*=n;
		n--;
	}

	return factorial;
}


int main(){
	int n,r;
	cin>>n>>r;
	cout<<n<<"C"<<r<<"="<<Factorial(n)/(Factorial(r)*Factorial(n-r))<<endl;
	return 0;
}