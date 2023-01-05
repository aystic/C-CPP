#include<iostream>
using namespace std;

bool Isprime(int n){
	int i;
	for( i=2;i<=n-1;i++){
		if(n%i==0)
			break;

	}
	if(i==n)
		return 1;
	return 0;
}

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(Isprime(i)==1){
			cout<<i<<" ";
		}
	}

	return 0;
}
