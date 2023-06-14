#include<iostream>
using namespace std;


void star(int n){
    for(int i=0;i<=3;i++){
        
        for(int j=0;j<3-i-1;j++){
            cout<<" "<<endl;

        }
        for(int j=0;j<2*i-1;j++){
            cout<<"*"<<endl;
        }
        for(int j=0;j<3-i-1;j++){
            cout<<" "<<endl;

        }
        cout<<endl;
        
    }

}
int main()
{
    star(3);

    return 0;
}