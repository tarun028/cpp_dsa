#include<iostream>
#include<vector>
#include<deque>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<map>


using namespace std;


int main(){

    //vector
    vector<int> v;
    v.push_back(1);
    cout<<"capacity->"<<v.capacity()<<endl;
    //deque , queue , stack
    deque<int>d;
    d.push_back(1);
    d.push_front(2);
    // d.at ,d.front , d.size

    d.size();
    d.erase(d.begin());

    //list

    set<int> s;
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    
    set<int>::iterator it = s.begin();
    it++;
    s.erase(it);
    
    map<int,string> m;
    m[1]="Tarun";
    m[2]="Tar";
    m[3]="Taru";

    m.insert({4,"ta"});
    for(auto i:m){
        cout<<i.first<<i.second;
    }




    return 1;
}