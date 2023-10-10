#include<iostream>
using namespace std;

//update mid = s+(e-s)/2; 

int BinarySearch(int arr[],int size,int key){
    int start=0;
    int end=size-1;

    int mid =start+(end-start)/2;

    while(start <= end){

        if(arr[mid]==key){
            cout<<mid;
            break;
        }

        //right
        if(key>arr[mid]){
            start=mid+1;
        }

        //left
        if(key<arr[mid]){
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
}
 
int main()
{
    int even[]={2,4,6,8,12,18};
    int odd[]= {3,8,10,32,65,88,90};
    BinarySearch(even,6,4);
    //cout<<ans;
    return 0;
}