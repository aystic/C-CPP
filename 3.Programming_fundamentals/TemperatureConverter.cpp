#include<iostream>
using namespace std;

int main(){
	int f=0;
	float c;
	while(f<=300){
		c=(float)(5*(f-32))/9;
		cout<<f<<" " <<c<<endl;
		f=f+20;
	}



	return 0;
}