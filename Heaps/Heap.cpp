#include <bits/stdc++.h>
using namespace std;

void insert(vector<int> &heap,int val)
{
	heap.push_back(val);
	int index=heap.size()-1;
	while(index>0)
	{
		int parent=(index-1)/2;
		if(heap[index]<heap[parent])
		{
			swap(heap[index],heap[parent]);
			index=parent;
		}
		else break;
	}
	
}

void heapify(vector<int> &heap,int pos)
{
	int min=pos;
	int l=2*pos+1;
	int r=2*pos+2;
	if(l<=heap.size()-1 && heap[l]<heap[min])
	        min=l;
	if(r<=heap.size()-1 && heap[r]<heap[min])
	        min=r;
	if(min!=pos)
	{   swap(heap[pos],heap[min]);
		heapify(heap,min);
	}
}

void remove(vector<int> &A,int pos)
{
	if(pos==A.size()-1)
		A.pop_back();
	else
	{
		int j=A.size()-1;
		A[pos]=A[j];
		A.pop_back();
		heapify(A,pos);
    }
}
int minheapmin(vector<int> &heap)
{
	if (heap.size()<1)
	   cout<<"Heap Underflow";
	return heap[0];
}
int minheapextract(vector<int> &heap)
{ 
	int min=minheapmin(heap);
	int j=heap.size()-1;
	heap[0]=heap[j];
	heap.pop_back();
	heapify(heap,0);
	return min;
}


int main()
{
	int n;
	cout<<"Enter the number of elements to add to the heap:";
	cin>>n;
	int b[n];
	vector<int> heap;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the element to be added to heap:";
		cin>>b[i];
	}
	for(int i=0;i<n;i++)
		insert(heap,b[i]);
	
	for(int i=0;i<heap.size();i++)
		cout<<heap[i]<<" ";
	cout<<endl;
	int r;
	cout<<"Enter the position of the element to be removed:";
	cin>>r;
    remove(heap,r);
	
	for(int i=0;i<heap.size();i++)
	{
		cout<<heap[i]<<" ";
	}
	cout<<endl;
	cout<<"The minimum value in heap:"<<minheapextract(heap)<<endl;
	
		for(int i=0;i<heap.size();i++)
	{
		cout<<heap[i]<<" ";
	}
}