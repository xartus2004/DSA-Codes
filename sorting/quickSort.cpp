#include <bits/stdc++.h>
using namespace std;
//Rules:
//1.Pick a pivot element and put it at its correct place
//2.Smaller elements in the left and larger on the right(in random order).

/*  It can be
        1.First Element of the array
        2.Last element of the array
        3.median element of the array
        4.random element of the array
*/

int f(int arr[],int low,int high)
{
    int pivot=low;
    int i=low;
    int j=high;
    while(i<j)
    {
        //We have i<=high-1 and j>=low-1 so that at the extreme ends when either i=high or j=low therir value don't go out of bound


        while(arr[i]<=arr[pivot] && i<=high-1)        //Here we have <= because we consider that if there are two equal element the other one will be on the left of the pivotal one
            i++;
        while(arr[j]>arr[pivot] && j>=low+1)          //Here we have > because we consider that if there are two equal element the other one will be on the left of the pivotal one
            j--;
        if(i<j)
            swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void qs(int arr[],int low,int high)
{
    if(low<high)
    {
        int pIndex=f(arr,low,high);     //Partition Index
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}

int main()
{
    int arr[8]={4,6,2,5,7,9,1,3};
    qs(arr,0,7);
    for(auto i:arr)
        cout<<i<<"\t";
}