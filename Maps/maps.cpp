#include <iostream>
#include <map>
using namespace std;

/*
key:value pairs
Red black Trees are used for implementation
Non-Contiguous Data Structure ( Each pair is stored in )
|
----->    i+1  //invalid    ❌
          i++  //Valid      ✅
*/

int main()
{
    // Initialization

    map<int,string> m;
    m[1]="abc";     //O( log n )
    m[5]="ccb";
    m[3]="bca";
    m[6];           //O( log n )

    //Insertion
    m.insert({4,"abb"});
    
    //Iterator
    map<int,string> :: iterator it;  

    for(it=m.begin();it!=m.end();it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;     //O( log n )
        cout<<it->first<<" "<<it->second<<endl;
    }

    //Size
    cout<<m.size()<<endl;
    for(auto pr:m)
        cout<<pr.first<<" "<<pr.second<<endl;

    //Find
    auto ite = m.find(3);       //O( log n )
    if(ite==m.end())
        cout<<"No Value"<<endl;
    else
        cout<<ite->first<<" "<<ite->second<<endl;
    
    //Erase - deleting element
    if(ite!=m.end())
        m.erase(ite);

    //Clear - deleting all elements
    m.clear();

    //Time complexity dependency on keys
    m[9]="aabbcc";      //s.size() * O(log n)
}

