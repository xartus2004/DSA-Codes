#include <bits/stdc++.h>
using namespace std;

struct Item{
    int profit,weight;

    Item(int profit,int weight)
    {
        this->profit=profit;
        this->weight=weight;
    }
};

static bool cmp(Item a,Item b)
{
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}

double fractionalKnapsack(int W,struct Item arr[],int N)
{
    sort(arr,arr+N,cmp);
    double totalProfit=0.0;

    for(int i=0 ; i<N ; i++)
    {
        if(W>arr[i].weight)
        {
            W-=arr[i].weight;
            totalProfit+=arr[i].profit;
        }
        else
        {
            totalProfit+=arr[i].profit*((double)W/(double)arr[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main()
{
    int W = 50;
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, N);
    return 0;
}