#include <iostream>
using namespace std;
//number of occurences
int occur(int (&arr)[10],int r)
{
    int count=0;
    int s=sizeof(arr)/sizeof(arr[0]);
    for(int &x:arr)
    {
        if(x==r)
            count++;
    }
    if(count==0)
        return -1;
    else
        return count;
}
int main()
{
    // int n;
    int k;
    // cout<<"Enter size of array: ";
    // cin>>n;
    int a[10]={0};
    //Taking array as input
    for( int i=0 ; i<10 ; i++ )
    {
        cin>>a[i];
    }
    cout<<"Enter the number to be found: ";
    cin>>k;
    cout<<"The number "<<k<< " occurs "<<occur(a,k)<<" times\n";
}