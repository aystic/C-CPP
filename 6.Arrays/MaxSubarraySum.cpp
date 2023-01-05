#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	cin>>n;
	int sum[n]={0};
	cin>>sum[0];
	for (int i = 1; i < n; ++i)
	{
		int temp;
		cin>>temp;
		sum[i]=sum[i-1]+temp;
	}
	int x,y;
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		if(sum[i]>max){
			max=sum[i];
			x=i;
			y=i-1;
		}

	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(sum[j]-sum[i]>max){
				max=sum[j]-sum[i];
				x=j;
				y=i;
			}
		}
	}
	cout<<"The max sum is "<<max<<endl;
	cout<<"From index "<<y+1<<" to "<<x<<endl;
	return 0;
}