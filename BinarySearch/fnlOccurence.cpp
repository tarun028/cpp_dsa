#include<iostream>
using namespace std;

int FirstOcc(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid =(start+end)/2;
    int ans=-1;

    while(start <= end){

        if(arr[mid]==key){
            ans=mid;
            end=mid-1;
        }

        //right
        else if(key>arr[mid]){
            start=mid+1;
        }

        //left
        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start + end)/2;
    }
    
}
int LastOcc(int arr[],int size,int key){
    int start=0;
    int end=size-1;
    int mid =(start+end)/2;
    int ans=-1;

    while(start <= end){

        if(arr[mid]==key){
            ans=mid;
            start=mid+1;
        }

        //right
        else if(key>arr[mid]){
            start=mid+1;
        }

        //left
        else if(key<arr[mid]){
            end=mid-1;
        }
        mid=(start + end)/2;
    }
    
}


int main()

{
    int even[]={1,2,3,3,5};
    cout<<"First Occ is: "<<FirstOcc(even,5,3)<<endl;
    cout<<"Last Occ is: "<<LastOcc(even,5,3);
    return 0;
}