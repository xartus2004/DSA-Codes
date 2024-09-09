#include <bits/stdc++.h>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s=="") return 0;
    int n=s.length();
    unordered_map<char,int> m;
    int l=1;    //length of logest substring
    int i=0,j=0;
    m[s[j]]++;
    if(n==1) return 1;
    while(i<=j && j<n-1){
        j++;
        cout<<"j:"<<j<<"i:"<<i<<endl;
        while(i<j && m.count(s[j])!=0 && s[i]!=s[j]){ //s[j] already exists
            cout<<j<<s[i]<<m[s[i]]<<endl;
            m[s[i]]--;
            i++;
            cout<<"i::"<<i<<endl;
        }
        if(s[i]==s[j]){
            m[s[i]]--;
            i++;
        }
        if(!m.count(s[j])){ //s[j] is absent
            m[s[j]]++;
        }
        // cout<<"["<<i<<","<<j<<"]"<<" "<<j-i+1;
        // cout<<j-i+1<<endl;
        l=max(l,j-i+1);
    }
    cout<<j<<endl;
    return l;
}
int main(){
    string s="tmmzuxt";
    cout<<lengthOfLongestSubstring(s);
}