#include <bits/stdc++.h>
using namespace std;

//Time Complexity : O(log n)
//Space Complexity : O(log n)

//We can max heapify index i only if both its subtrees are heaps
//Hence we start heapify from down to up

int MaxHeapify(int A[],int N,int i)
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

int Build_MaxHeap(int A[],int N)
{
    for(int i=N/2+1 ; i>=0 ; i--)
        MaxHeapify(A,N,i);
}

//Time Complexity : O (NlogN)
//Space Complexity : O (logN)

void HeapSort(int A[] , int N)
{
    Build_MaxHeap(A,N);
    for(int i=N-1 ; i>=0 ; i--)
    {
        swap(A[0],A[i]);
        MaxHeapify(A,N,0);
    }
}



int main()
{
    
}