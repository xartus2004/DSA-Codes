#include <bits/stdc++.h>
using namespace std;

    int f(vector<int> &arr,int low,int high)
    {
        int pivot=low;
        int i=low;
        int j=high;
        while(i<j)
        {
            //We have i<=high-1 and j>=low-1 so that at the extreme ends when either i=high or j=low their value don't go out of bound

            while(arr[i]<=arr[pivot] && i<=high-1)        //Here we have <= because we consider that if there are two equal element the other one will be on the left of the pivotal one
                i++;
            while(arr[j]>arr[pivot] && j>=low+1)          //Here we have > because we consider that if there are two equal element the other one will be on the left of the pivotal one
                j--;
            if(i<j)
                swap(arr[i],arr[j]);
        }
        swap(arr[low],arr[j]);
        return j;
    }

    void QuickSort(vector<int> &arr,int low,int high)
    {
        if(low<high)
        {
            int pIndex=f(arr,low,high);     //Partition Index
            QuickSort(arr,low,pIndex-1);
            QuickSort(arr,pIndex+1,high);
        }
    }


    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        QuickSort(people,0,n-1);
        for(auto i:people)  cout<<i<<" ";
        cout<<endl;
        int boats=0,i=0,j=0;
        int sum=0;
        while(j<n){
            // cout<<people[j]<<" ";
            cout<<sum+people[j]<<"<"<<limit<<endl;
            while(sum+people[j]<=limit){
                cout<<"Hi";
                sum+=people[j];
                j++;
                cout<<j<<"->";
            }
            i=j;
            boats++;
            sum=0;
        }
        return boats;
    }


int main(){
    vector<int> people = {3,5,3,4};
    int limit = 5;
    cout<<numRescueBoats(people,limit);
}