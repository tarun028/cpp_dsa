#include<iostream>
using namespace std;


void altRev(int arr[],int n){
    for(int i=0;i<n;i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

void printArr(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void duplicate(int arr[],int n){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    cout<<ans;
    cout<<endl;
}

int main()
{

    int even[6]={1,2,3,4,5,6};
    int odd[5]={1,2,3,4,5,};
    int dupli[5]={1,2,3,2,1};
    //altRev(even,6);
    duplicate(dupli,5);
    //printArr(even,6);
    return 0;
}

