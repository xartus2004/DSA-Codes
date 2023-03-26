#include <iostream>
#include <math.h>
using namespace std;
//Applicable only for sorted array

//Iterative Binary Search
int bSearch(int arr[],int n,int x)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==x)
            return mid;
        else if(arr[mid]>x)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

//Recursive Binary Search
int rbSearch(int arr[],int k,int high,int low)
{
    while(low<=high)
    {
        int mid=(low+high)/2;
        if (arr[mid]==k)
            return mid;
        else if(arr[mid]>k)
            return rbSearch(arr,k,mid-1,low);
        else
            return rbSearch(arr,k,high,mid+1);
    }
    if(low>high)    
        return -1;
}


//First occurence of a element

//Iterative
int foccur(int arr[],int n,int k)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        //---Normal Binary search
        int mid=(low+high)/2;
        if(arr[mid]>k)
            high=mid-1;
        else if(arr[mid]<k)
            low=mid+1;
        //---Normal Binary search--end
        else
        {
            //Additional Condition
            if(mid==0 || arr[mid]!=arr[mid-1])
                return mid;
            //Add. cond. --end
            else
                high=mid-1;
        }
    }
    return -1;
}

//Recursive
int foccur1(int arr[],int k,int high,int low)   //high and low are required for recursive calls 
{
    if(low>high)    return -1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]<k)  return foccur1(arr,k,high,mid+1);
        else if(arr[mid]>k) return foccur1(arr,k,mid-1,low);
        else
        {
            if(mid==0 || arr[mid]!=arr[mid-1])
                return mid;
            else
                return foccur1(arr,k,mid-1,low);
        }
    }
}

//Last occurence of an element

int loccur(int arr[],int n,int k)
{
    int low=0,high=n-1;
    if(low>high)
        return -1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]>k)
            high=mid-1;
        else if(arr[mid]<k)
            low=mid-1;
        else
        {
            if(mid==0 || arr[mid]!=arr[mid+1])
                return mid;
            else
                low=mid+1;
        }
    }
}

//Last Occurence Recursive 
int rloccur(int arr[],int k,int low,int high)
{
    if(low>high)    return -1;
    while(low<=high)
    {
        int mid=(high+low)/2;
        if(arr[mid]>k)  return rloccur(arr,k,low,mid-1);
        else if(arr[mid]<k) return rloccur(arr,k,mid+1,high);
        else
        {
            if(mid==0 || arr[mid]!=arr[mid+1])
                return mid;
            else
                return rloccur(arr,k,mid+1,high)
        }
    }
}

//No of occurences

int countOcc(int arr[],int n,int k)
{
    int first=foccur(arr,n,k);
    if(first==-1)
        return 0;
    else
        return (loccur(arr,n,k)-first+1);
}

//No of 1's
int ones(int arr[],int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==0)
            low=mid+1;
        else
        {
            if(mid==0 || arr[mid-1]==0)
                return n-mid;
            else
                high=mid-1;
        }
    }
    if (low>high)   return -1
}

//Application of Binary Search

//1.Square Root Of a Number

int sqRootFloor(int x)
{
	int low = 1, high = x, ans = -1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		int mSq = mid * mid;

		if(mSq == x)
			return mid;
		else if(mSq > x)
			high = mid - 1;
		else
		{
			low = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

//2.Finding in an infinite array

int inffind(int arr[],int k)
{
    if arr[0]==k    return 0;
    int i=1;
    while(arr[i]<k)
    {
        i=i*2;
    } 
    if (arr[i]==k)  return i;
    return rbSearch(arr,k,i,i/2+1);
}

//Search in Sorted rotated array
int srfind(int arr[],int n,int k)
{
    //------Like normal binary search---------
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if(arr[mid]==k) return mid;
        //------Left half sorted--------------
        if (arr[low]<=arr[mid])
        {
            if(x>=arr[low] && x<arr[mid])
                low=mid+1;
            else
                high=mid+1;
        }
        //-------Right Half Sorted------------
        else
        {
            if(x>arr[mid] && x<=arr[high])
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return -1;
}

//Peak element
int peak(int arr[],int n)
{
    int low=0,high=n-1;
    while(low<=high)
    {
        int mid=(low+high)/2;
        if((arr[mid]==0 || arr[mid-1]<arr[mid])&&(arr[mid]==n-1 || arr[mid]>arr[mid+1]))
                return mid;
        if(mid>0 && arr[mid]<=arr[mid-1])
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}
//Two Pointers Approach for to find if there is a pair with sum x
bool pairx(int arr[],int n,int x)
{
    int i=0,j=n-1;
    while(i<j)
    {
        if(arr[i]+arr[j]==x)
            return true;
        else if(arr[i]+arr[j]>x)
            j--;
        else
            i++
    }
    return false;
}
//Median of 2 Sorted Arrays
int median(int arr1[],int arr2[],int n1,int n2)
{
    int lo=0,hi=n1;//assuming arr1 is the smaller
    while(lo<=hi)
    {
        int cut1=(lo+hi)/2;
        int cut2=(n1+n2)/2-cut1;
        int l1=cut1==0?INT_MIN:arr1[cut1-1];
        int l2=cut==0?INT_MIN:arr2[cut2-1];
        int r1=cut1==n1?INT_MAX:arr1[cut1];
        int r2=cut2==n2?INT_MAX:arr2[cut2];
        if(l1>r2)   hi=cut1-1;
        else if(l2>r1)  lo=cut1+1;
        else    return (n1+n2)%2==0 ? (max(l1,l2)+min(r1,r2))/2 : min(r1,r2);
    }
}
int main()
{
    int m;
    int k;
    cout<<"Enter size of array: ";
    cin>>m;
    int a[m]={0};
    //Taking array as input
    for( int i=0 ; i<m; i++ )
    {
        cin>>a[i];
    }
    cout<<"Enter the number to be found: ";
    cin>>k;
    // cout<<"The number "<<k<< " occurs at "<<bSearch(a,m,k)<<"\n";
    // cout<<"The number "<<k<< " occurs at "<<rbSearch(a,k,m-1,0)<<"\n";
    // cout<<"The number "<<k<< " first occurs at "<<foccur(a,m,k)<<"\n";
    // cout<<"The number "<<k<< "  occurs "<<countOcc(a,m,k)<<" times \n";
    return 0;
}
