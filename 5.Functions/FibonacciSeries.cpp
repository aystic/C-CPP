//program to print the nth term of the fibonacci series

#include<iostream>
using namespace std;

int fibonacci(int n){
	int term;
	if(n==1)
		return 0;
	else if(n==2)
		return 1;
	else 
		term=fibonacci(n-1)+fibonacci(n-2);
	return term;
}

int main(){
	int n;
	cin>>n;
	cout<<"The "<<n<<"th term in the fibonacci sequence is "<<fibonacci(n)<<endl;

	return 0;
}