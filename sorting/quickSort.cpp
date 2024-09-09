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

int f(vector<int> &arr,int low,int high)
{
    int pivot=low;
    int i=low;
    int j=high;
    while(i<j)
    {
        //We have i<=high-1 and j>=low-1 so that at the extreme ends when either i=high or j=low their value don't go out of bound

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

void QuickSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int pIndex=f(arr,low,high);     //Partition Index
        QuickSort(arr,low,pIndex-1);
        QuickSort(arr,pIndex+1,high);
    }
}

int main()
{
    vector<int> arr={3,5,4,3};
    QuickSort(arr,0,3);
    for(auto i:arr)
        cout<<i<<"\t";
}