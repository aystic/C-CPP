#include<iostream>
#include<climits>
using namespace std;

int main(){
	int n;
	cin>>n;
	int min=INT_MAX;
	int max=INT_MIN;
	int a;
	while(n--){
		cin>>a;
		if(a<min)
			min=a;
		if(a>max)
			max=a;
	}
	cout<<"Minimum "<<min<<" "<<"Maximum "<<max<<endl;

	return 0;
}