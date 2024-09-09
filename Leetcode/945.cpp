#include <bits/stdc++.h>
#include <iostream>
#define nline "\n"
using namespace std;

int minIncrementForUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count=0;
    map<int,int> m;

    for(int i=0 ; i<nums.size() ; i++){
        m[nums[i]]++;
    }

    for(auto it:m){
        cout<<it.first<<"->"<<it.second<<nline;
    }
    int i=nums.front();
    while(i<nums.back()||m[i]>0){
        if(m[i]<1)    continue;
        if(m[i]>1){
            count+=(m[i]-1);
            m[i+1]+=(m[i]-1);
        }
        i++;
    }
    for(auto it:m){
        cout<<it.first<<"->"<<it.second<<nline;
    }

    return count;
}

int main()
{
    vector<int> vec = {1,2,2,2};
    cout<<minIncrementForUnique(vec);
}