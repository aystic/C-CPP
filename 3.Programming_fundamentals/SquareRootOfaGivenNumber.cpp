#include<iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int p;
	cin>>p;
	float root=0;
	float sum=10.0;
	for(int i=1;i<=p+1;i++){
		sum=sum/10;
		while((root*root)<=n){
		root+=sum;
		}
		root=root-sum;
	}
	cout<<"Root of "<<n<<" is "<<root<<endl;
	return 0;
}