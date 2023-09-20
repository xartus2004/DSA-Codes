#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(log n)
//Space Complexity : O(log n)

//We can max heapify index i only if both its subtrees are heaps
//Hence we start heapify from down to up

void MaxHeapify(vector<int> &A,int N,int i)
{
    int L=2*i+1;
    int R=2*i+2;
    int largest;
    if(L<N && A[L]>A[i])
        largest=L;
    else
        largest=i;

    if(R<N && A[R]>A[largest])
        largest=R;
    
    if(largest!=i)
    {
        swap(A[largest],A[i]);
        MaxHeapify(A,N,largest);
    }
}

//It seems that the time complexity for this would be O(n logn)

//But it is O(N)

//For perfect binary tree
//At any level h Max no of nodes = [ N / 2^(h+1)]
//For almost complete binary tree it is always less than this

//Total Time = logN ∑ h=0    [ N / 2^(h+1)] . O(h)
//NOTE: ∞ ∑ h=0   (h/2^h) = 2

void Build_MaxHeap(vector<int> &A,int N)
{
    for(int i=N/2+1 ; i>=0 ; i--)
        MaxHeapify(A,N,i);
}

//Time Complexity : O (NlogN)
//Space Complexity : O (logN)

void HeapSort(vector<int> &A , int N)
{
    Build_MaxHeap(A,N);
    // for(int i=0 ; i<N ; i++)
    //     cout<<A[i]<<"\t";
    cout<<endl;
    for(int i=N-1 ; i>=0 ; i--)
    {
        swap(A[0],A[i]);
        MaxHeapify(A,i,0);
    }
}

int extractMax(vector <int> &A,int N)
{
    int Maximum=A[0];
    A[0]=A[N-1];
    A.pop_back();
    MaxHeapify(A,--N,0);
    return Maximum;
}

void IncrementKey(vector <int> &A,int N,int i,int key)
{
    A[i]=key;
    while(i>0 && A[i/2]<A[i])
    {
        swap(A[i],A[i/2]);
        i/=2;
    }
}

void DecrementKey(vector <int> &A,int N,int i,int key)
{
    A[i]=key;
    MaxHeapify(A,N,i);
}

void InsertElement(vector <int> &A,int N,int key)
{
    A.push_back(key);
    int i=N-1;
    while(i>0 && A[i/2]<A[i])
    {
        swap(A[i],A[i/2]);
        i/=2;
    }
}

void RemoveNode(vector<int> &A,int i)
{
	if(i==A.size()-1)
		A.pop_back();
	else
	{
		int j=A.size()-1;
		A[i]=A[j];
		A.pop_back();
		MaxHeapify(A,A.size(),i);
    }
}

void PrintHeap(vector<int> &A)
{
    for(int i=0 ; i<A.size() ; i++)
        cout<<A[i]<<"\t";  
    cout<<endl;
}

int main()
{
    int n=7;
    int arr[n]={6,5,3,7,2,1,8};
    vector<int> a;
    for(int i=0 ; i<n ; i++)
        a.push_back(arr[i]);
    // //Heapsort
    // HeapSort(a,n);
    // PrintHeap(a);

    //Heap Operations
    Build_MaxHeap(a,n);
    //Printing the Sorted array
    PrintHeap(a);

    // //Extract Maximum
    // int m=extractMax(a,n);
    // cout<<"The Max Element is "<<m<<endl;
    // PrintHeap(a);

    //Increment Key
    IncrementKey(a,n,6,12);
    PrintHeap(a);

    // //Decrement Key
    // DecrementKey(a,n,2,2);
    // PrintHeap(a);

    // //Insert Element
    // InsertElement(a,n,12);
    // PrintHeap(a);

    // //Remove Element
    // RemoveNode(a,5);
    // PrintHeap(a);
}