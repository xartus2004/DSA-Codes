#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number to be prime factorized:";
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        while(n%i==0)
        {
            cout<<i<<",";
            n=n/i;
        }
    }
}