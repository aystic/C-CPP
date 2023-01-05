#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	int s=0,e=n-1;
	cout<<"Enter the sum : ";
	int sum;
	cin>>sum;
	while(s<=e){
		if(a[s]+a[e]<sum){
			s++;
		}else if(a[s]+a[e]>sum){
			e--;
		}else{
			cout<<"Index "<<s<<" and index "<<e<<" when summed gives the required sum : "<<sum<<endl;
			if(a[s+1]==a[s])
				s++;
			else if(a[e-1]==a[e])
				e--;
			else{
				s++;
				e--;
			}
		}
	}

	return 0;
}