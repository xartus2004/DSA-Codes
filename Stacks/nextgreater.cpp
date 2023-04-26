//Paranjay Dubey
//2022BCS-051

//next greater element using stack 
#include <iostream>
#include <stack>
using namespace std;

void nextgreater(int arr[],int n)
{
    int nql[n];
    stack<int>stk;
    for(int i=2*n-1 ; i>=0 ; i--)
    {
        while(!(stk.empty()) && arr[i%n]>=stk.top())
        {
            stk.pop();
        }
        if(i<n)
        {
            if(stk.empty()==false)
                nql[i]=stk.top();
            else
                nql[i]=-1;
        }
        stk.push(arr[i%n]);
    }
    cout<<"The next greater elements are"<<endl;
    for(auto i:nql)
        cout<<i<<" ";
}

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++)
    {
        cout<<"Enter "<<i<<"th element: ";
        cin>>arr[i];
    }
    nextgreater(arr,n);
}