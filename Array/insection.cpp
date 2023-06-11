#include<iostream>
using namespace std;

void Inter(int arr1[],int arr2[],int n,int m){
    int ans;
    for(int i=0;i<n;i++){
        int elem = arr1[i];
        for(int j=0;j<m;j++){

            if(elem<arr2[j]){
                break;
            }
            if(elem==arr2[j]){
                ans=elem;
                break;
            }
            
        }
    }
    cout<<ans;

}
int main()
{
    int arr1[]={1,2,3};
    int arr2[]={3,4}; 
    Inter(arr1,arr2,3,2);
    

    return 0;
}