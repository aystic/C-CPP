#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long int a;//can store upto 19 digits
		cin>>a;
		int sum=0;
		int pow=1;
		while(a>0){
			sum+=(pow*(a%10));
			pow*=2;
			a=a/10;
		}
		cout<<sum<<endl;
	}

	return 0;
}