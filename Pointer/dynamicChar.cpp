#include<iostream>
using namespace std;
int main()
{
    char ch='a';
    cout<<sizeof(ch)<<endl;
    char* ptr = &ch;
    cout<<sizeof(ptr)<<endl;
    char* ptr1 = new char;
    cout<<sizeof(ch);

    return 0;
}