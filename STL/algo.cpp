#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
    
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    cout<<"hehe"<<binary_search(v.begin(),v.end(),4)<<endl;
    
    //lower_bound()

    int a=10;
    int b=20;
    cout<<"max"<<max(a,b); //min
    swap(a,b);
    cout<<endl<<a<<b<<endl;

    string str="1234";
    reverse(str.begin(),str.end());
    cout<<str<<endl;
    

}