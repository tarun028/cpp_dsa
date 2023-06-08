#include <iostream>

using namespace std;

void printf1(int n){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


void printf2(int n){
    for(int i=0;i<=5;i++){
        //space
        for(int j=0;j<5-i-1;j++){
            cout<<" ";
        }
        //star
        for(int j=0;j<2*i+1;j++){
            cout<<"*";
        }
        //space
        for(int j=0;j<5-i-1;j++){
            cout<<" ";
        }
        cout<<endl;
    }
}



int main()
{
    
    //printf1(5);
    printf2(5);
    

    return 0;
}