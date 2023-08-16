#include<iostream>
using namespace std;
int main()
{
    int a[10]={1,2,3,4,5,-9,-1,-100};
    int mn=a[0];
    for (int i = 0; i < 9; i++)
    {
        /* code */
        if(a[i] < mn){
            mn = a[i];
        }
    }
    cout<<"Min: "<<mn<<endl;
    
    return 0;
}