#include<iostream>
using namespace std;
int main()
{
    int s;
    int arr[4]={30,20,50,81};
    for(int &x : arr)
    {
        cout<<x<<endl;
    }
    return 0;
}
