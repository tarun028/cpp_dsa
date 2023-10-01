#include<iostream>
using namespace std;
int main()
{
    int a[5]={1,2,3,4,5};
    int n =7;
    int s=0;
    int e=4;
    while(s<e){
        

        if(a[s]+a[e]==n){
            cout<<a[s]<<" "<<a[e]<<endl;
            break;
        }
        else if(a[s]+a[e]<n){
            s++;
        }
        else{
            e--;
        }
    }
    if(s>=e){
        cout<<"not found"<<endl;
    }
    return 0;
}