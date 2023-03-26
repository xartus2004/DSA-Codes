#include <iostream>
using namespace std;
int counting_numbers(int arr[],int s)
{
    bool is_distinct=true;
    int count=0;
    for(int i=0;i<s;i++)
    {
        for(int j=0;j<s;j++)
        {
            if(arr[i]==arr[j])
            {
                is_distinct=false;
            }
        }
        if(is_distinct==true)
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int S[10]={1,2,3,2,4,5,5,7,8,7};
    int s=sizeof(S)/sizeof(S[0]);
    int c=counting_numbers(S,s);
    cout<<c;
}