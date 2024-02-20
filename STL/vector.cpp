#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    cout<<"Size"<<v.capacity()<<endl;

    v.push_back(1);
    v.push_back(2);
    cout<<"capacity"<<v.capacity()<<endl;
    return 0;
}