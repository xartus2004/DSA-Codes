//Paranjay Dubey
//2022BCS-051

//next greater element using stack 
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    int arr[]={1,2,3,4,5};
    int brr[5];
    stack<int> myst;
    for (int i = 4; i >=0; i--)
    {
        if (i==4)
        {
          brr[i]=-1  ;
          myst.push(arr[i]);
        }
        else
        {
            while (!myst.empty() && arr[i]>=myst.top())
            {
               myst.pop();
            }
            if (myst.empty())
            {
                brr[i]=-1;
                myst.push(arr[i]);
            }
            else
            {
                brr[i]=myst.top();
                myst.push(arr[i]);
            }  
        }
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<brr[i]<<endl;
    }
    return 0;

}