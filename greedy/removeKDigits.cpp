#include<bits/stdc++.h>
using namespace std;

string removeKdigits(string num, int k) {
    int i=1;
    int l=num.length();

    while(k>0 && i<l)
    {
        if(num[i-1]>=num[i]){
            num.erase(i-1,1);
            k--;
            i--;
        }
        i++;
    }
    int j=0;
    while(num[j]=='0'){
        num.erase(j,1);
    }

    if(num[0]==''){
        num='0';
    }
    return num;
}

int main(){
    string str="10200";
    int k=1;
    cout<<removeKdigits(str,k);
}