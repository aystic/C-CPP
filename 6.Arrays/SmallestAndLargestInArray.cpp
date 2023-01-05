#include<iostream>
#include<climits>
using namespace std;

int main(){
	int largest=INT_MIN;
	int smallest=INT_MAX;
	int a[10];
	for (int i = 0; i < 10; ++i)
	{
		cin>>a[i];
	}
	for (int i = 0; i < 10; ++i)
	{
		// if(a[i]>=max)
		// 	max=a[i];
		largest=max(largest,a[i]);
		// if(a[i]<=min)
		// 	min=a[i];
		smallest=min(smallest,a[i]);
	}
	cout<<"The max and min in array are "<<largest << " "<<smallest<<endl;
	return 0;
}