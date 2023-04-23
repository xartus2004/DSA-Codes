//Paranjay Dubey
//2022BCS-051
//Balanced Paranthesis

#include <iostream>
#include <stack>
using namespace std;
int nextgreater(stack <int> stk,int x)
{
    int max=stk.top();
    while(stk.top()!=x)
    {
        if (stk.top()>max)
            max=stk.top();
        stk.pop();          
    }

    return max;
}

int main()
{
    int n,x;
    stack<int>stk;
    cout<<"Enter length of stack";
    cin>>n;

    // arr1 stores the elements being pushed into the stack
    // arr stores the maximum element above them

    int arr[n],arr1[n];

    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter an element: ";
        cin>>x;
        stk.push(x);
        arr1[i]=x;
    }

    for(int i=0 ; i<n ; i++)
        arr[i]=nextgreater(stk,arr1[i]);

    for(auto i:arr)
        cout<<i<<" ";
}