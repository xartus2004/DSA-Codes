#include <iostream>
#include <stack>
using namespace std;

string reverse(string str)
{
    stack <char> stk;
    string ans;
    for(auto i:str)
        stk.push(i);
    while(!stk.empty())
    {
        ans=ans+stk.top();
        stk.pop();
    }
    return ans;
} 

int main()
{
    string s;
    cin>>s;
    cout<<reverse(s);
}