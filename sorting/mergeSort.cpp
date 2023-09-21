// Recursive C++ program for merge sort
#include<bits/stdc++.h>
using namespace std;


// Function to merge the two halves
// arr[l..m] and arr[m+1..r] of array arr[]

void merge(int arr[], int l, int m, int r)
{
	int k;  //size of array
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for(int j = 0; j < n2; j++)
		R[j] = arr[m + 1+ j];

	int i = 0;
	int j = 0;
	k = l;
	
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < n1)
		arr[k++] = L[i++];

	// Copy the remaining elements
	// of R[], if there are any
	while (j < n2)
		arr[k++] = R[j++];
}

// Function to print an array
void printArray(int A[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", A[i]);
		
	cout << "\n";
}

// l is for left index and r is
// right index of the sub-array
// of arr to be sorted
void mergeSort(int arr[], int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2 but avoids
		// overflow for large l & h
		int m = (l+r)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}

// Function to print an array
void printArray(int A[], int size)
{
	for(int i = 0; i < size; i++)
		printf("%d ", A[i]);
		
	cout << "\n";
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}