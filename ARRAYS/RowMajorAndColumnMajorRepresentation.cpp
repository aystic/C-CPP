/*
* @Author: Mohit Pathak
* @Date:   2021-02-04 16:49:13
* @Last Modified by:   Mohit Pathak
* @Last Modified time: 2021-02-04 17:11:57
*/
#include <iostream>
using namespace std;

int main() {
    int arr[3][4][5] {0};
    int val=1;

    /*
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            *(*arr+i*4+j)=val;
            val++;
        }
    }
    
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<*(*arr+i*4+j)<<" ";
        }
        cout<<endl;
    }
    */

    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 4; ++j)
    	{
    		for (int k = 0; k < 5; ++k)
    		{
    			*(*(*arr+i)+j*20+k*5)=val;
    			val++;
    		}
    	}
    }

    for (int i = 0; i < 3; ++i)
    {
    	for (int j = 0; j < 4; ++j)
    	{
    		for (int k = 0; k < 5; ++k)
    		{
    			cout<<arr[i][j][k]<<" ";
    		}
    		cout<<endl;
    	}
    }


	return 0;
}
