#include <bits/stdc++.h>
using namespace std;

int main(){
    //creation
    unordered_map<string,int> m;

    //insertion
    //1
    pair<string,int> p = make_pair("paranjay",19);
    m.insert(p);

    //2
    pair<string,int> p2("dubey",7);
    m.insert(p2);

    //3
    m["ashu"]=2004;
    //updation
    m["ashu"]=022004;

    //Search
    cout<<m["paranjay"]<<endl;
    cout<<m["dubey"]<<endl;

    cout<<m.at("kanak")<<endl;    //exception generated

    /*******/
    cout<<m["kanak"]<<endl;       //return 0 as no such entry exists and stores this new entry as ("kanak",0)
    cout<<m.at("kanak")<<endl;    //no exception returns 0(created in prev line)

    //size
    cout<<m.size()<<endl;
     
    //to check presence
    cout<<m.count("paranjay")<<endl;    //0 if absent 1 if present

    //erase
    m.erase("dubey");
    cout<<m.size()<<endl;

    //iteration
    //1
    for(auto i:m)   
        cout<<i.first<<" "<<i.second<<endl;
    
    //2
     unordered_map<string,int>::iterator it = m.begin();

     while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;  
     }

    m["dubey"];     //no change if already exists
    cout<<m.at("dubey");    //

    return 0;
}