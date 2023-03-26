#include <iostream>
#include <vector>
void print(int arr[][2],int m)  //It is not necessary to pass the number of rows
{
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<n ; j++)
            cout<<arr[i][j]<< " ";
    }
}

//Using Double Pointers
void print2(int** arr , int m , int n)
{
    //Same as above       
}
//Using Array of Pointers
void print3(int *arr[] , int m , int n)
{
    //Same as above
}
//Using array of vectors
int print4(vector<int> arr[],int m)
{
    for(int i=0 ; i<m ; i++)
    {
        for(int j=0 ; j<arr[i].size() ; j++)
        {
            cout<<arr[i][j]<< " ";
        }
    }
}
int print5(vector<vector<int>> &arr)
{
    for(int i=0 ; i<arr.size() ; i++)
    {
        for(int j=0 ; j<arr[i].size() ; j++)
        {
            cout<<arr[i][j]<< " ";
        }
    }
}