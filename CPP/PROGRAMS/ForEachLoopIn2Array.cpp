#include<iostream>
using namespace std;


int main(){
    int arr[10][10];
    int val=1;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            arr[i][j]=val;
            val++;
        }
    }
    for(int *x:arr){
        for (int y[10]:x)
        {
            cout<<y<<" ";
        }
        cout<<endl;
    }

    // for(auto &x:arr){
    //     for(auto y:x)
    //         cout<<y<<" ";
    //     cout<<endl;
    // }


    return 0;
}