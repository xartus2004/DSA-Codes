#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // //----NOTE----
    // //1.Elements are stored in row major order
    // int arr[3][2]={{10,20},{30,40},{50,60}};
    // //Depiction of row major
    // //2.Internal curly brackets are optional
    // int arr[3][2]={10,20,30,40,50,60};
    // //This is same as the above
    // //3.Only the first dimension can be omitted when we initialize
    // int arr[][2][2]={{10,20},{30,40},{50,60}};


    // //1. Double Pointer

    // //ADVANTAGE:- We can create multidimentional array with different sizes of rows
    // int rows=3,cols=2;
    // int **a=new int *[rows];
    // for(int i=0 ; i<rows ; i++)
    //     arr[i]=new int [cols];
    // for(int i=0 ; i<rows ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //     {
    //         arr[i][j]=10;
    //         cout<<arr[i][j]<<" ";
    //     }
    // }   

    // //2. Array of Pointers

    // int *arr[rows];
    // for(int i=0 ; i<rows ; i++)
    //     arr[i]=new int[cols];

    // for(int i=0 ; i<m ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //         cout<<arr[i][j]<<" ";
    // }

    // //**NOTE**
    // //The difference between double pointer and array of pointers is that in Double pointer approach Heap(Dynamic Allocation) of Addresses pointing to all rows was created
    // //While in array of pointers an array storing addresses of rows is created

    // //3. Array of Vectors

    // int m=3,n=2;
    // vector<int> arr[m];
    // for(int i=0 ; i<m ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //         arr.push_back(10)
    // }
    // for(int i=0 ; i<m ; i++)
    // {
    //     for(int j=0 ; j<n ; j++)
    //         cout<<arr[i][j]<<" ";
    // }
    // //Not as cache friendly as simple 2D array
    // //Individual rows of dynamic sizes
    // //Easy to pass to a function


    // //4. Vector of Vector

    // int m=3,n=2;
    // vector<vector<int>> arr;
    // for(int i=0 ; i<m ; i++)
    // {
    //     vector<int> v;
    //     for(int j=0 ; j<n ; j++)
    //     {
    //         int ele;
    //         cin>>ele;
    //         v.push_back(ele);
    //     }
    //     arr.push_back(v);
    // }


    //Passing 2D arrays as an argument
    
}