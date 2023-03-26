#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++)
    {
        for(int h=1 ; h<=n-i+1 ; h++)
            cout<<" ";
        for(int j=1 ; j<=i ; j++ )
            cout<<j<<"";
        for(int k=i-1 ; k>=1 ; k--)
            cout<<k<<"";
        cout<<endl;
    }
}