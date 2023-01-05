/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 14:39:48
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 15:25:26
*/
#include<iostream>
using namespace std;

class rectangle{
private:
	int length;
	int breadth;
public:
	rectangle(int l=0,int b=0){
		length=l;
		cout<<l<<endl;
		breadth=b;
		cout<<b<<endl;
	}
	int getlength(){
		return length;
	}
	int getbreadth(){
		return breadth;
	}
	int area(){ return length*breadth;}
	int perimeter(){ return 2*(length+breadth);}
};

int main(){
	rectangle r1{999,1};
	rectangle r2{r1};
	cout<<r1.getlength()<<" "<<r1.getbreadth()<<endl;
	cout<<r2.getlength()<<" "<<r2.getbreadth()<<endl;
	return 0;

}