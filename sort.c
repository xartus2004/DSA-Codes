//Name: Paranjay Dubey
//Roll No: 2022BCS-051
//Date: 19-02-2023
#include <stdio.h>
//Sorting 
int main()
{
    //Taking array as input
    int n;
    printf("Enter Size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements: ");
    for(int i=0 ; i<n ; i++)
        scanf("%d",&arr[i]);
    
    //Sorting the array using bubble sort

    for(int i=n-1 ; i>=0 ; i--)
    {
        for(int j=0 ; j<i ; j++)
        {
            if(arr[j]>arr[j+1])
            {
                //if an element is smaller than its preceding element they are swapped
                arr[j]=arr[j]+arr[j+1];
                arr[j+1]=arr[j]-arr[j+1];
                arr[j]=arr[j]-arr[j+1];
            }
        }
    }

    //Printing the sorted array
    for (int t=0 ; t<n ; t++)
        printf("%d\t",arr[t]);

}