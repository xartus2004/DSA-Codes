#include <iostream>
#include <stack>
using namespace std;
bool balanced(string str)
{
    stack <char> stk;
    for(int i=0 ; i<str.length() ; i++)
    {
        if(i=='('|| i=='{' || i=='[')
            stk.push(i);

        else if( (i==')' && stk.top()=='(') ||
                 (i=='}' && stk.top()=='{')||
                 (i==']' && stk.top()=='['))
        {
            stk.pop();            
        }
    }
    return stk.empty();
}

int main()
{
    string str;
    cout<<"Enter a string with paranthesis: ";
    cin>>str;
    bool t=balanced(str);
    if(t)
        cout<<"The paranthesis is balanced";
    else
        cout<<"The paranthesis is not balanced";
}   