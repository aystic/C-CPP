#include<iostream>
using namespace std;

// int LinearSearch(int n,int a[20],int size){
// int LinearSearch(int n,int a[],int size){
// int LinearSearch(int n,int* a,int size){
int LinearSearch(int n,int* a,int size){
	for (int i = 0; i < size ; ++i)
	{
		if(a[i]==n)
			return i;
	}

	return -1;
}

int main(){
	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		cin>>a[i];
	}
	cout<<"Enter the element to be searched :";
	int n;
	int size=sizeof(a)/sizeof(int);
	cin>>n;
	if(LinearSearch(n,a,size)==-1){
		cout<<"Element not present"<<endl;
	}
	else{
		cout<<"Element present at the "<<LinearSearch(n,a,size)<<" index"<<endl;
	}
	return 0;
}