#include <bits/stdc++.h>
using namespace std;

bool isNStraightHand(vector<int>& hand, int groupSize) {

    if(!hand.size()%groupSize)  return false;

    map<int,int> Hash;
    for(auto i:hand){
        Hash[i]++;
    }

    for(auto h:Hash){
        cout<<h.first<<" "<<h.second<<endl;
    }

    while(!Hash.empty()){
        int curr = Hash.begin()->first;
        cout<<"curr"<<curr<<" "<<Hash[curr]<<endl;

        
        for(int i=0 ; i<groupSize ; i++){
            if(Hash[curr+i])    Hash[curr+i]--;
            else                return false;
            if(Hash[curr+i]<1){
                Hash.erase(curr+i);
            }
        }
    }
    return true;
}

int main(){
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int groupSize = 3;
    cout<<bool(isNStraightHand(hand,groupSize))<<endl;
}