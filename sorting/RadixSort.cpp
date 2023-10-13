#include <bits/stdc++.h>
using namespace std;
int getMax(int arr[],int n)
{
    int res=arr[0];
    for(int i=1 ; i<n ; i++)
    {
        if(arr[i]>res)
            res=arr[i];
    }
    return res;
}

void countingSort(int arr[],int n,int div)
{
    int output[n];
    int count[10]={0,};

    for(int i=0 ; i<n ; i++)
        count[(arr[i]/div)%10]++;
    
    for(int i=1 ; i<10 ; i++)
        count[i]+=count[i-1];
    
    for(int i=n-1 ; i>=0 ; i--)
    {
        output[count[(arr[i]/div)%10]-13]=arr[i];
        count[(arr[i]/div)%10]--;
    }

    for(int i=0 ; i<n ; i++)
        arr[i]=output[i];
}

void radixSort(int arr[],int n)
{
    int m=getMax(arr,n);

    for(int div=1 ; m/div>0 ; div*=10)
        countingSort(arr,n,div);
}

int main()
{
    int a[] = {210, 378, 563, 765, 92, 33, 0, 6};
    int n=8;

    cout << "Initial: ";
    for (int i=0;i<n;i++)
        cout <<a[i]<< " ";

    radixSort(a,n);

    cout << "\nFinal: ";
    for (int i=0;i<n;i++)
        cout <<a[i]<<" ";

    return 0;
}