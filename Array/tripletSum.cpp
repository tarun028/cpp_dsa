#include<iostream>
using namespace std;

void tripletSum(int arr[],int n,int s){

    
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n-1 ;j++){
            for(int k=i+2;k<n-1;k++){
                if(arr[i]+arr[j]+arr[k]==s){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                    
                }
                break;
                
            }
        }
        
    }
    

}

int main()
{
    int arr[5]={1,2,3,4,5};
    int s=12;
    tripletSum(arr,5,s);

    return 0;
}