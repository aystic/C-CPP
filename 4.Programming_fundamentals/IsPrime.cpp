#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i=0;
	for( i=2;i<n;i++){
		if(n%i==0)
			break;
	}
	if(i==n){
		cout<<n<<" is prime."<<endl;
	}else{
		cout<<n<<" is not prime"<<endl;
	}
	return 0;
}