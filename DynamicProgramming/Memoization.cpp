#include <bits/stdc++.h>'
using namespace std;

int fibonacci(int n,vector <int> &dp)
{
    if(n<=1)
        return n;
    //This return the value directely if already calculated
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fibonacci(n-1,dp)+fibonacci(n-2,dp);   //Stores solution to this subproblem
}

int main()
{
    int n;
    //We create a dynamic programming array to store all subproblemss to avoid overlapping subproblems
    
    vector <int> dp(n+1,-1);
    fibonacci(5,dp);
}