#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
    //Sort function is present in the algorithm libraray
    //Syntax
    //sort(position of first element,position next to the last element)


    //Time Complexity : O(n log n)
    //By default it uses Quick Sort
    //If quick sort takes more time it switches to heapsort
    //Whwn array size is small it switches to insertion sort
    
    int arr[]={10,20,5,7};
    int n=4;


    sort(arr,arr+n);

    //for decreasing order

    sort(arr,arr+n,greater<int>());

    for(int &x:arr)
    {
        cout<<x<<" ";
    }
    cout<<endl;

    //Vectors
    vector<int> v={5,7,20,10};
    sort(v.begin(),v.end());
    for(int x:v)
        cout<<x<<" ";
    cout<<endl;

    sort(v.begin(),v.end(),greater<int>());

    for(int x:v)
        cout<<x<<" ";
    cout<<endl;
}