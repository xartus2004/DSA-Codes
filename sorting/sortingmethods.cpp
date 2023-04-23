#include <iostream>
using namespace std;

//Bubble Sort
int main()
{
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
    int n=10;
    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<i ; j++)
        {
            if (arr[j]>arr[j+1])
            {
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
    }
    for(auto x:arr)
        cout<<x<<" ";
}