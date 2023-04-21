//Paranjay Dubey
//2022BCS-051
//Balanced Paranthesis

#include <iostream>
#include <stack>
using namespace std;
bool balanced(string str)
{
    // stack created
    stack <char> stk; 

    for(int i=0 ; i<str.length() ; i++)
    {
        char temp=str[i];
        if(temp=='('|| temp=='{' || temp=='[')
            stk.push(temp);

        else if( (temp==')' && stk.top()=='(') ||
                 (temp=='}' && stk.top()=='{')||
                 (temp==']' && stk.top()=='['))
        {
            stk.pop();            
        }
    }
    return stk.empty();
}

int main()
{
    //Taking number of test cases from the user

    int t;
    cout<<"Enter no of test cases: ";
    cin>>t;

    for(int i=0 ; i<t ; i++)
    {
        string str;
        cout<<"Enter a string with paranthesis: ";
        cin>>str;
        bool t=balanced(str);
        if(t)
            cout<<"The paranthesis is balanced"<<endl;
        else
            cout<<"The paranthesis is not balanced"<<endl;
    }
}