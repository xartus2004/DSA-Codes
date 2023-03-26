//Operations on Array
/*
1.Searching
2.Insertion
3.Deletion
4.Largest
5.Second Largest
6.Reversal
7.Removal of duplicates
*/

#include <iostream>
using namespace std;
// //Searching (unsorted array)
// int search(int arr[],int n,int x)
// {
//     //n is size of array
//     //x is the element to be searched for
//     for(int i=0 ;   i<n ;   i++)
//     {
//         if(arr[i]==x)
//         {
//             return i;
//         }
//     }
//     return -1;  //represents array
// }

// //Insertion (unsorted array)
// int insert(int arr[],int n,int x,int cap,int pos)
// {
//     //n is size of array
//     //x is the element to be inserted
//     //cap is the size of array
//     //pos is the position where x is to be inserted
//     if (n==cap)
//         return n;
//     int idx=pos-1;  //index of the position where x is to be inserted
//     for(int i=n-1 ; i>=idx ; i--)
//         arr[i+1]=arr[i];
//     arr[idx]=x;
//     return (n+1);
//     //Time Complexity: O(n)
//     //Time Complexity at the end: O(1)
//     //Time Complexity: O(n)
// }

// //Deletion
// int deletion(int arr[],int n,int x)
// {
//     int i;
//     for(i=0 ; i<n ; i++)
//     {
//         if(arr[i]==x)
//             break;
//     }
//     if (i==n)   //it iterated till the end of the array but couldn't find x
//         return n;
//     for(int j=i ; j<n-1 ; j++)
//         arr[j]=arr[j+1];
//     arr[n-1]=0;
//     return (n-1);
// }

// // int main()
// // {
// //     int a[5]={1,2,3,4,5};
// //     int y=deletion(a,5,4);
// //     for(int &x:a)
// //         cout<<x<<" ";
// //     return 0;
// // }

// //Largest
// int largest(int arr[],int n)
// {
//     int i;
//     int x=arr[0];
//     for(i=1 ; i<n ; i++)
//     {
//         if(x<arr[i])
//             x=arr[i];

//     }
//     return (i-2);
// }

// //Second Largest Element

// //This is the program that i made
// //In the process it also edits the array which is not a good thing
int secondlargest(int arr[],int n)
{
    int idx1=largest(arr,n);
    arr[idx1]=arr[0];
    int i;
    int x=arr[0];
    for(i=1 ; i<n ; i++)
    {
        if(x<arr[i])
            x=arr[i];

    }
    return x;
}
// // int main()
// // {
// //     int a[5]={200,100,50,5000,30};
// //     int y=secondlargest(a,5);
// //     cout<<y;
// // }


// //Check if array is sorted

// int ifsorted(int arr[],int n)
// {
//     int i;
//     int x=arr[0];
//     for(i=1 ; i<n ; i++)
//     {
//         if(arr[i-1]>arr[i])
//             return false;

//     }
//     return (i-2);
// }


// //Reversing

// int main()
// {
//     int arr[]={1,2,3,4,5};
//     int n=sizeof(arr)/sizeof(arr[0]);
//     for(int i=0 ; i<(n/2) ; i++)
//     {
//         arr[i]=arr[i]+arr[n-i-1];
//         arr[n-i-1]=arr[i]-arr[n-i-1];
//         arr[i]=arr[i]-arr[n-i-1];
//     }
//     for(int i=0 ; i<n ; i++)
//     {
//         cout<<arr[i]<<" ";
//     }
// }

//Moving Zeroes to End
void zero(int A[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        if(A[i]==0)
        {
            for(int j=i ; j<n ; j++)
            {
                A[j]=A[j]+A[j+1];
                A[j+1]=A[j]-A[j+1];
                A[j]=A[j]-A[j+1];
            }
        }
    }
    for(int k=0 ; k<n ; k++)
    {
        cout<<A[k]<<"\t";
    }
}
int main()
{
    int arr[10]={3,0,0,4,8,0,7,0,0,3};
    zero(arr,10);
}