#include<iostream>
using namespace std;

int main(){
	int a[10]={0};
	int b[10];
	for(int i=0;i<5;i++){
		cin>>b[i];
	}
	for(int i=0;i<10;i++){
		cout<<b[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<10;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"Size of array is "<<sizeof(a)<<" and number of values are "<<sizeof(a)/sizeof(int)<<endl;

	return 0;
}