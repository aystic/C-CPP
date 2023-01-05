/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 14:13:47
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 14:19:03
*/
#include<iostream>
using namespace std;

class rectangle{
private:
	int length;
	int breadth;
public:
	void setlength(int a){
		if(a>0){
			length=a;
		}else{
			length=0;
		}
	}
	void setbreadth(int a){
		if(a>0){
			breadth=a;
		}else{
			breadth=0;
		}
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
	rectangle r;
	r.setlength(10);
	r.setbreadth(50);
	cout<<"length is "<<r.getlength()<<endl;
	cout<<"breadth is "<<r.getbreadth()<<endl;
	cout<<r.area()<<" "<<r.perimeter()<<endl;
	return 0;
}