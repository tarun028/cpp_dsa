#include<iostream>
#include<array>

using namespace std;
int main()
{
    array<int,4> a={1,2,3,4};
    int size = a.size();

    for(int i =0;i<size;i++){
        cout<<a[i]<<endl;
    }
    cout<<"at"<<a.at(3)<<endl;
    cout<<"empty"<<a.empty()<<endl;
    cout<<"front or back"<<a.front()<<endl;
    return 0;
}