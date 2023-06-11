#include<iostream>
using namespace std;

void PairSum(int arr[],int n,int s){

    int one=0;
    int two=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1 ;j++){
            if(arr[i]+arr[j]==s){
                cout<<arr[i]<<" "<<arr[j];
            }
            break;
        }
        cout<<endl;
    }
    

}

int main()
{
    int arr[5]={1,2,3,4,5};
    int s=5;
    PairSum(arr,5,s);

    return 0;
}