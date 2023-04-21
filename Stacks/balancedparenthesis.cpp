#include <iostream>
#include <stack>
using namespace std;
bool balanced(string str)
{
    stack <char> stk;
    for(int i=0 ; i<str.length() ; i++)
    {
        if(i=='('|| i=='{' || i=='[')
        {
            stk.push(i);
        }
        else if( (i==')' && stk.top()=='(') ||
                 (i=='}' && stk.top()=='{')||
                 (i==']' && stk.top()=='['))
        {
            stk.pop();            
        }
        else
            stk.push(i);
    }
    if(stk.empty())
        return true;
    else
        return false;
}

int main()
{
    string str;
    cin>>str;
    bool t=balanced(str);
    cout<<t; 
}   