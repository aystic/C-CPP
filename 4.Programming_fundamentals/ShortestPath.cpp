#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int x=0,y=0;
	char movement;
	movement=cin.get();
	while(movement!='\n'){
		if(movement=='E' || movement=='e')
			++x;
		else if(movement=='W' || movement=='w')
			--x;
		else if(movement=='N'||movement=='n')
			++y;
		else if(movement=='S' || movement=='s')
			--y;
		movement=cin.get();
	}
	cout<<"Final Position is ("<<x<<","<<y<<")"<<endl;
	cout<<"Dispalcement is "<<sqrt(x*x+y*y)<<endl;
	if(x<0){
		while(x!=0){
			cout<<"W";
			x++;
		}
	}else if(x>0){
		while(x!=0){
			cout<<"E";
			x--;
		}
	}
	if(y<0){
		while(y!=0){
			cout<<"S";
			y++;
		}
	}else if(y>0){
		while(y!=0){
			cout<<"N";
			y--;
		}
	}
	cout<<endl;
	return 0;
}