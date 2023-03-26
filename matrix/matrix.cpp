#include <iostream>
using namespace std;
//Transpose of an nxn matrix
void transpose(int ** arr,int n)
{
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<n ; j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
}
int main()
{
    int rows=3,cols=3;
    int **a=new int *[rows];
    for(int i=0 ; i<rows ; i++)
        a[i]=new int [cols];
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            int n;
            cin>>n;
            a[i][j]=n;
        }
        cout<<"\n";
    }
    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    transpose(a,cols);
    cout<<"\n";

    for(int i=0 ; i<rows ; i++)
    {
        for(int j=0 ; j<cols ; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}