/*
* @Author: Mohit Pathak
* @Date:   2021-01-31 11:59:58
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-01-31 12:02:11
*/
#include<iostream>
using namespace std;

class rectangle{
public:
	int length;
	int breadth;
	int area(){
		return length*breadth;
	}
	int perimeter(){
		return 2*(length+breadth);
	}
};

int main(){
   rectangle r1;
   r1.length=10;
   r1.breadth=50;
   cout<<r1.area()<<endl;
   cout<<r1.perimeter()<<endl;
   return 0;
}	