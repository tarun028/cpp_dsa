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
int main()
{

    int even[6]={1,2,3,4,5,6};
    int odd[5]={1,2,3,4,5,};

    altRev(even,6);
    printArr(even,6);
    return 0;
}

