#include <bits/stdc++.h>
using namespace std;

void countingSort(int arr[],int n)
{
    int count[10]={0,};
    for(int i=0 ; i<n ; i++)
    {
        count[arr[i]]++;
        // if(i!=0)
        //     count[arr[i]]+=count[arr[i-1]];
    }

    for(int i=1 ; i<10 ; i++)
    {
        count[i]+=count[i-1];
    }

    int k=0;
    for(int i=0 ; i<10 ; i++)
    {
        for(int j=k ; j<count[i] ; j++)
        {
            cout<<i<<"\t";
            k++;
        }
    }
    cout<<endl;
    
}

int main()
{
    int n;
    cout<<"Enter Size of Input Array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the Elements: ";
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    
    countingSort(arr,n);
}