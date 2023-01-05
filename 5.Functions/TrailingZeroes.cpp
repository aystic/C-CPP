#include<iostream>
using namespace std;

int trailing_zeroes(int n){
	int temp;
	int sum=0;
	temp=n/5;
	while(temp!=0){
		sum+=temp;
		temp=temp/5;

	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	cout<<"Trailing Zeroes in "<<n<<"!"<<" are "<<trailing_zeroes(n)<<endl;

	return 0;
}